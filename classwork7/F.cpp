#include <iostream>
using namespace std;

enum Status { Continue = 100, OK = 200, Created = 201, Accepted = 202, Bad_Request = 400, Unauthorized = 401, 
	Not_Found = 404, Method_Not_Allowed = 405, Internal_Server_Error = 500, Not_Implemented = 501, Bad_Gateway = 502};

int main() {
	int temp;
	cin >> temp;
	while (temp != 0) {
		switch (temp) {
		case Status::Continue:
			cout << "Continue";
			break;
		case Status::OK:
			cout << "OK";
			break;
		case Status::Created:
			cout << "Created";
			break;
		case Status::Accepted:
			cout << "Accepted";
			break;
		case Status::Bad_Request:
			cout << "Bad Request";
			break;
		case Status::Unauthorized:
			cout << "Unauthorized";
			break;
		case Status::Not_Found:
			cout << "Not Found";
			break;
		case Status::Method_Not_Allowed:
			cout << "Method Not Allowed";
			break;
		case Status::Internal_Server_Error:
			cout << "Internal Server Error";
			break;
		case Status::Not_Implemented:
			cout << "Not Implemented";
			break;
		case Status::Bad_Gateway:
			cout << "Bad Gateway";
			break;
		}

		cout << endl;

		cin >> temp;
	}
}