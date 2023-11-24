

#include <iostream>
using namespace std;
#include"22i-2513_DS.h"


int main()
{
	DirectoryTree d;
	int x=-1;

	while (true) {
			cout << "\n<=====================MENU-DRIVEN================================================>\n";
		cout << "1. Creating dirextorises\n2. Creating Files\n3. Display Tree\n4. Search\n5. Rename\\deleting_File OR Folder(directories)\n6. Copying and MOving File and directories\n7. merging the directories\n8. Exporting to file\n9. Importing from file\n0. Exit\n";
		cin >> x;
		if (x == 1) {
			d.createDirectory1();
		}
		else if (x == 2) {
			d.creatingfile();
		}
		else if(x == 3) {
			cout << "\n<=====================DISPLAY TREES===============================================>\n";

			d.ListingDirectoryTree();

		}
		else if (x == 4) {
			cout << "\n<=====================SEARCH FILE & DIRECTORIES====================================>\n";

			d.Search();
		}
		else if (x == 5) {
			cout << "\n<=====================DELELTE / RENAAME FILE & DIRECTORIES=========================>\n";

			d.Deleting_Renaming_FilesAndFolder();
		}
		else if (x == 6) {
			cout << "\n<=====================COPY & MOVE===================================================>\n";

			d.CopyandMove();
		}
		else if (x == 7) {
			cout << "\n<=====================MERGING DIR====================================================>\n";

			d.mergingDirectories();
		}
		else if (x == 8) {
			cout << "\n<=====================EXPORTING FILE=================================================>\n";

			d.exportToFile();
		}
		else if (x == 9) {
			cout << "\n<=====================IMPORTING FILE=================================================>\n";

			d.importFromFile();
		}
	
		else if (x == 0) {
			exit(0);
		}
	}
	
	return 0;
}
