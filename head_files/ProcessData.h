#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <sstream>
#include <cstdio>
using namespace std;

// 分割字符串函数（适配制表符分隔）
vector<string> split(const string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter)) {
		// 去除前后空格和制表符
		size_t start = token.find_first_not_of("\t");
		size_t end = token.find_last_not_of("\t");
		if (start != string::npos && end != string::npos) {
			tokens.push_back(token.substr(start, end - start + 1));
		}
		else {
			tokens.push_back("");
		}
	}
	return tokens;
}

// SQLite 回调函数（用于错误信息处理）
static int callback(void* data, int argc, char** argv, char** azColName) {
	return 0;
}

// 安全执行 SQL 语句的封装函数
bool executeSQL(sqlite3* db, const string& sql, const string& errorMsg) {
	char* zErrMsg = nullptr;
	int rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);
	if (rc != SQLITE_OK) {
		cerr << errorMsg << ":" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		return false;
	}
	return true;
}

// 转义 SQL 字符串中的特殊字符，防止注入和格式错误
string escapeSQL(const string& str) {
	if (str.empty()) return "";
	char* escaped = sqlite3_mprintf("% q", str.c_str());
	string result(escaped);
	sqlite3_free(escaped);
	return result;
}

void ImportData() {
	string filename;
	cout << "请输入 TXT 文件名（不包含.txt）：";
	cin >> filename;

	// 构建完整的文件名
	string txtFilename = "./GTE_Data" + filename + ".txt";
	const string dbFilename = "./GTE_Data/Database.db"; // 数据库名

	// 打开 TXT 文件
	ifstream file(txtFilename);
	if (!file.is_open()) {
		cerr << "错误：无法打开文件" << txtFilename << "，请检查文件是否存在" << endl;
		return;
	}

	// 打开 SQLite 数据库
	sqlite3* db = nullptr;
	int rc = sqlite3_open(dbFilename.c_str(), &db);
	if (rc != SQLITE_OK || db == nullptr) {
		cerr << "错误：无法打开数据库" << dbFilename << "，原因：" << sqlite3_errmsg(db) << endl;
		sqlite3_close(db); // 确保资源释放
		return;
	}

	// 创建表的 SQL 语句（只包含需要存储的列）
	string createTableSQL = "CREATE TABLE IF NOT EXISTS" + filename + "("
		"Date TEXT PRIMARY KEY,"
		"Open REAL,"
		"High REAL,"
		"Low REAL,"
		"Close REAL,"
		"Change REAL,"
		"ChangePercent REAL,"
		"Volume REAL,"
		"Turnover REAL"
		");";

	if (!executeSQL(db, createTableSQL, "创建表失败")) {
		sqlite3_close(db);
		return;
	}
	cout << "表" << filename << "创建成功或已存在" << endl;

	// 读取并解析 TXT 文件内容
	string line;
	size_t lineNumber = 0;
	size_t successCount = 0;
	size_t skipCount = 0;

	// 跳过标题行
	if (!getline(file, line)) {
		cerr << "错误：文件" << txtFilename << "为空，没有数据可导入" << endl;
		sqlite3_close(db);
		file.close();
		return;
	}
	lineNumber++;

	// 读取数据行
	while (getline(file, line)) {
		lineNumber++;
		vector<string> fields = split(line, '\t'); // 使用制表符分隔

		// 检查字段数量是否符合预期（根据文件内容，应为 15 列）
		if (fields.size() != 15) {
			cerr << "警告：第" << lineNumber << "行格式错误，字段数量不符（实际：" << fields.size() << "，预期：15），已跳过" << endl;
			skipCount++;
			continue;
		}

		try {
			// 提取需要的列（严格指定 vector<string>的元素类型）
			const string date = escapeSQL(fields[0]);
			const string open = fields[6];
			const string high = fields[7];
			const string low = fields[8];
			const string close = fields[9];
			const string change = fields[10];
			const string changePercent = fields[11];
			const string volume = fields[12];
			const string turnover = fields[13];

			// 构建插入 SQL 语句（处理空值和特殊字符）
			string insertSQL = "INSERT OR IGNORE INTO" + filename + "("
				"Date, Open, High, Low, Close, Change,ChangePercent,Volume, Turnover"
				") VALUES ('" +
				date + "'," +
				(open.empty() ? "NULL" : open) + "," +
				(high.empty() ? "NULL" : high) + "," +
				(low.empty() ? "NULL" : low) + "," +
				(close.empty() ? "NULL" : close) + "," +
				(change.empty() ? "NULL" : change) + "," +
				(changePercent.empty() ? "NULL" : changePercent) + "," +
				(volume.empty() ? "NULL" : volume) + "," +
				(turnover.empty() ? "NULL" : turnover) +
				");";

			if (executeSQL(db, insertSQL, "插入第" + to_string(lineNumber) + "行失败")) {
				successCount++;
				// 每 100 行输出一次进度，避免过多打印
				if (successCount % 100 == 0) {
					cout << "已成功导入" << successCount << "行数据（当前行：" << lineNumber << "）" << endl;
				}
			}
			else {
				skipCount++;
			}
		}
		catch (const exception& e) {
			cerr << "处理第" << lineNumber << "行时发生异常：" << e.what() << "，已跳过" << endl;
			skipCount++;
			continue;
		}
	}

	// 清理资源
	file.close();
	sqlite3_close(db);

	// 输出导入统计信息
	cout << "\n 数据导入完成！" << endl;
	cout << "总处理行数：" << (lineNumber - 1) << "（已排除标题行）" << endl;
	cout << "成功导入：" << successCount << "行" << endl;
	cout << "跳过 / 失败：" << skipCount << "行" << endl;
	cout << "数据库文件：" << dbFilename << endl;
}

void ExportData() {
}