#include <iostream>

using namespace std;

int main()
{
	float import;
	char Tipus;

	cout << "Import: ";
	cin >> import;

	cout << endl;

	cout << "Tipus: ";
	cin >> Tipus;

	if (((Tipus == 'B') || (Tipus == 'S')) || (Tipus == 'P')) {

		switch (Tipus)
		{
		case 'B':
			cout << "El import es : " << import << endl;
			break;
		case 'S':
			if (import > 10000)
			{
				import = import - (import*0.05);
				cout << "El import es : " << import << endl;
				break;
			}
			else
				cout << "El import es : " << import << endl;
			break;
		case 'P':
			if (import > 10000)
			{
				import = import - (import *0.2);
				cout << "El import es : " << import << endl;
				break;
			}
			else if ((import > 1000) && (import <= 10000))
			{
				import = import - (import *0.10);
				cout << "El import es : " << import << endl;
				break;
			}
			else if ((import > 100) && (import <= 1000))
			{
				import = import - (import *0.05);
				cout << "El import es : " << import << endl;
				break;
			}
			else
				cout << "El import es : " << import << endl;
			break;
		default:
			break;
		}
	}
	else
		cout << "ERROR " << endl;
	return 0;
}