#include "User.h" 

using namespace std;

string base64_encode(string const& s, bool url);
int isInt();

class UserRepository
{
private:
	vector<User> Registered;

public:
	bool filling() {
		ifstream lgn("C:\\Users\\Захар\\Desktop\\Orders-services\\Orders-services\\Oreders_2\\login.txt");
		string data;
		if (lgn.is_open()) {
			while (!lgn.eof())
			{
				User user;
				getline(lgn, data, '\n');
				user.setLogin(data);
				getline(lgn, data, '\n');
				user.setPassword(data);
				getline(lgn, data, '\n');
				int v = atoi(data.c_str());
				user.setStatus(v);
				getline(lgn, data, '\n');
				Registered.push_back(user);
			}
			Registered.pop_back();
		}
		lgn.close();
		return 0;
	}

	User get(string& login) {
		for (auto o : Registered) {
			if (o.getLogin() == login) {
				return o;
			}
		}
		return User();
	}

	vector<User> getAll() {
		return Registered;
	}

	bool saveNewUser(User& usr) {
		Registered.push_back(usr);
		return 0;
	}

	bool saveUser(User&  usr, string& lg) {
		for (int i = 0; i < Registered.size(); i++) {
			if (Registered[i].getLogin() == lg) {
				Registered[i] = usr;
				return 0;
			}
		}
	}

	bool deleteUser(User& usr) {
		for (int i = 0; i < Registered.size(); i++) {
			if (usr.getLogin() == Registered[i].getLogin()) {
				Registered.erase(Registered.begin() + i);
			}
			i++;
		}
		return 0;
	}

	bool saveUsers() {
		fstream lgn("C:\\Users\\Захар\\Desktop\\Orders-services\\Orders-services\\Oreders_2\\login.txt");
		if (lgn.is_open()) {
			for (User x : Registered) {
				if (x.getStatus() != 0) {
					lgn << x.getLogin() << "\n" << x.getPassword() << "\n" << x.getStatus() << "\n*\n";
				}

			}
		}
		lgn.close();
		return 0;
	}
};
