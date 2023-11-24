#pragma once

#include <iostream>
#include<queue>
#include<fstream>
//#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Node {
public:
	string path;
	string name;
	string type;
	Node* left;
	Node* right;
	Node(string path,string name,string type):path(path),name(name),type(type),left(nullptr),right(nullptr) {}
};
class DirectoryTree {
private:
	
public:
	Node* root;
	DirectoryTree():root(nullptr){}  
// Function to create a new directory node and add it to the tree
    Node* CreateDirectory(Node* currentNode) {
        string name, path, type;
        cout << "\nEnter the name of directory: ";
        cin >> name;
        cout << "\nEnter the path of directory: ";
        cin >> path;
        cout << "\nEnter the type of directory: ";
        cin >> type;

        int which = 0;
        cout << "Enter [1] for patient directory and [2] for logs directory:\n\n";
        cin >> which;

        if (currentNode == nullptr) {
           
            currentNode = new Node("/", "root", "system");
            root = currentNode;  
        }

        Node* newNode = new Node(path, name, type);  

        if (which == 1) {
            if (currentNode->left == nullptr) {
                // If the left child is empty, add the new directory as the left child
                currentNode->left = newNode;
            }
            else {
               
                cout << "directory is Not Empty again enter details:\n";
                currentNode->left = CreateDirectory(currentNode->left);
            }
        }
        else if (which == 2) {
            if (currentNode->right == nullptr) {
                
                currentNode->right = newNode;
            }
            else {
               
                cout << "directory is Not Empty again enter details:\n";
                currentNode->right = CreateDirectory(currentNode->right);
            }
        }
        else {
            cout << "Invalid choice!\n";
        }

        return currentNode;  
    }
    void createDirectory1() {
        root = CreateDirectory(root);
    }
    // Function to create a new file node and add it to a patient or logs directory
    Node* CreateFile(Node* root) {
       string name, path, type;
       cout << "\nEnter the name of File: ";
        cin >> name;
        cout << "\nEnter the path of File: ";
        cin >> path;
        cout << "\nEnter the type of File: ";
        cin >> type;

        int which = 0;
        cout << "Enter [1] for patient FILE and [2] for logs file:\n\n";
        cin >> which;

        if (root == nullptr) {
            root = new Node("/", "root", "system");
        }

        if (which == 1) {
            Node* currentNode = root->left;
            while (currentNode != nullptr) {
                if (currentNode->right == nullptr) {
                    Node* newFile = new Node(path, name, type);
                    currentNode->right = newFile;
                    return root; 
                }
                else {
                    currentNode = currentNode->left; 
                }
            }
            cout << "No empty patient directory found on the left side.\n";
        }
        else if (which == 2) {
            Node* currentNode = root->right;
            while (currentNode != nullptr) {
                if (currentNode->left == nullptr) {
                   
                    Node* newFile = new Node(path, name, type);
                    currentNode->left = newFile;
                    return root; }
                else {
                    currentNode = currentNode->right; 
                }
            }
            cout << "No empty logs directory found on the right side.\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

        return root;
    }


    void levelOrderTraversal(Node* root) {
        if (root == nullptr) {
            cout << "The directory tree is empty." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* currentNode = q.front();
            q.pop();

            cout << "Path: " << currentNode->path << " | Name: " << currentNode->name << " | Type: " << currentNode->type << endl;

            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }
    }

	void creatingfile() {
		root=CreateFile(root);
	}
	// Displaying a Level order tree  for Module
	void ListingDirectoryTree(){
        levelOrderTraversal(root);
	}
	// merging the directories for the module
	/*void mergingDirectories() {

	}*/



    Node* DeleteFile(Node* root, const string& fileName, const string& filePath) {
        if (root == nullptr) {
            
            return nullptr;  // File not found
        }

        // Check if the current node is the file to delete
        if (root->name == fileName && root->path == filePath) {
            delete root; 
            return nullptr; 
        }

        
        root->left = DeleteFile(root->left, fileName, filePath);
        root->right = DeleteFile(root->right, fileName, filePath);

        return root;
    }

    
    Node* DeleteDirectory(Node* root, const string& directoryName) {
        if (root == nullptr) {
            // cout << "not found\n";
            return nullptr;  
        }

       
        if (root->name == directoryName) {
            delete root; 
            return nullptr; 
        }

       
        root->left = DeleteDirectory(root->left, directoryName);
        root->right = DeleteDirectory(root->right, directoryName);

        return root;
    }

    
    void RenameFile(Node* root, const string& currentFileName, const string& currentFilePath, const string& newFileName) {
        if (root == nullptr) {

            
            return; 
        }

       
        if (root->name == currentFileName && root->path == currentFilePath) {
            root->name = newFileName; 
            return;
        }

       
        RenameFile(root->left, currentFileName, currentFilePath, newFileName);
        RenameFile(root->right, currentFileName, currentFilePath, newFileName);
    }

    // Function to rename a directory by name
    void RenameDirectory(Node* root, const string& currentDirectoryName, const string& newDirectoryName) {
        if (root == nullptr) {
            //cout << "not found\n";
            return; 
        }

        
        if (root->name == currentDirectoryName) {
            root->name = newDirectoryName; 
            return;
        }

        
        RenameDirectory(root->left, currentDirectoryName, newDirectoryName);
        RenameDirectory(root->right, currentDirectoryName, newDirectoryName);
    }



	// able to delete files
	void Deleting_Renaming_FilesAndFolder() {
        string fileName, filePath, currentFileName, currentFilePath, newFileName;
        string dirName, currentDirectoryName, newDirectoryName;
        int x1 = 0;
        cout <<"\n1.delete file\n2.delete directory\n3.rename file\n4.rename directory" << endl;
        cin >> x1;
        if (x1 == 1) {
            cout << "\nEnter the name of the file to delete: ";
            cin >> fileName;
            cout << "\nEnter the path of the file to delete: ";
            cin >> filePath;
            root = DeleteFile(root, fileName, filePath);
        }
        else if (x1 == 2) {
            cout << "\nEnter the name of the directory to delete: ";
            cin >> dirName;
            root = DeleteDirectory(root, dirName);
        }
        else if (x1 == 3) {
            cout << "\nEnter the current name of the file to rename: ";
            cin >> currentFileName;
            cout << "\nEnter the current path of the file to rename: ";
            cin >> currentFilePath;
            cout << "\nEnter the new name for the file: ";
            cin >> newFileName;
            RenameFile(root, currentFileName, currentFilePath, newFileName);
        }
        else if (x1 == 4) {
           cout << "\nEnter the current name of the directory to rename: ";
           cin >> currentDirectoryName;
           cout << "\nEnter the new name for the directory : ";
           cin >> newDirectoryName;
            RenameDirectory(root, currentDirectoryName, newDirectoryName);
        }
        else {
            cout << " \nInvalid input !\n";
        }
	}
   
	
	// able to search directories of file and patient

    bool SearchFile(Node* root, const string& fileName, string& filePath) {
        if (root == nullptr) {
            return false;  
        }

        if (root->name == fileName) {
            
            filePath = root->path;
            return true;
        }

        
        if (SearchFile(root->left, fileName, filePath) || SearchFile(root->right, fileName, filePath)) {
            
            if (root->path != "/") {
                filePath = root->path + "/" + filePath;
            }
            return true;
        }

        return false;  
    }

	
	bool searchDirectory(Node* root, const string& directoryName) {
		if (root == nullptr) {
			return false;
		}

		if (root->name == directoryName) {
			cout << "Directory '" << directoryName << "' found.\n";
			return true;
		}

		return searchDirectory(root->left, directoryName) || searchDirectory(root->right, directoryName);
	}

	void Search() {
		int choice;
		cout << "Enter [1] to search for a file, [2] to search for a directory: ";
		cin >> choice;

		if (choice == 1) {
			string fileName,filePath;

            cout << "Enter the name of the file to search: ";
            cin >> fileName;
            if (SearchFile(root, fileName, filePath)) {
                cout << "File found at path: " << filePath << endl;
            }
            else {
                cout << "File not found." << endl;
            }
		}
		else if (choice == 2) {
			string directoryName;
			cout << "Enter the directory name to search: ";
			cin >> directoryName;

			bool found = searchDirectory(root, directoryName);
			if (!found) {
				cout << "Directory '" << directoryName << "' not found.\n";
			}
		}
		else {
			cout << "Invalid choice!\n";
		}
	}
    //find directory 
    Node* find_file(Node* root, const string& fileName) {
        if (root == nullptr) {
            cout << "File '" << fileName << "' not found.\n";
            return nullptr;
        }

        if (root->name == fileName && (root->type == "pdf" || root->type == "txt")) {
            cout << "File '" << fileName << "' found.\n";
            return root;
        }

        Node* foundInLeft = find_file(root->left, fileName);
        if (foundInLeft != nullptr) {
            return foundInLeft;
        }

        return find_file(root->right, fileName);
    }

    Node* insertInSpot(Node* root, Node* nodeToInsert) {
        if (root == nullptr) {
            return nodeToInsert;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* currentNode = q.front();
            q.pop();

           
            if (currentNode->left == nullptr) {
                currentNode->left = nodeToInsert;
                return root;
            }
            else {
                q.push(currentNode->left);
            }

            
            if (currentNode->right == nullptr) {
                currentNode->right = nodeToInsert;
                return root;
            }
            else {
                q.push(currentNode->right);
            }
        }

        return root; 
    }

    Node* copyfile(Node* root, const string& currentName, const string& currentPath, const string& filename) {
        if (root == nullptr) {
            return nullptr; 
        }

        if (root->name == currentName && root->path == currentPath && (root->type == "pdf" || root->type == "txt")) {
            Node* destination = find_file(this->root, filename);  

            if (destination != nullptr) {
                Node* copynode = new Node(currentName, currentPath, root->type);  

                if (destination->left == nullptr) {
                    cout << "succesfull";
                    destination->left = copynode;
                }
                else if (destination->right == nullptr) {
                    cout << "succesfull";
                    destination->right = copynode;
                }
                else {
                    
                    return insertInSpot(this->root, copynode);
                }

                return copynode;  
            }
            else {
                return nullptr;  
            }
        }

        
        Node* copiedFromLeft = copyfile(root->left, currentName, currentPath, filename);
        if (copiedFromLeft != nullptr) {
            return copiedFromLeft;
        }

        return copyfile(root->right, currentName, currentPath, filename);
    }
    Node* movefile(Node* root, const string& currentName, const string& currentPath, const string& destinationName) {
        static Node* parentMove = nullptr; 

        if (root == nullptr) {
            return nullptr;  
        }

        if (root->name == currentName && root->path == currentPath) {
            
            if (parentMove != nullptr) {
                if (parentMove->left == root) {
                    parentMove->left = nullptr;
                }
                else {
                    parentMove->right = nullptr;
                }
            }

            
            parentMove = nullptr;

            
            Node* destination = find_file(this->root, destinationName);

            if (destination != nullptr) {
                
                return insertInSpot(destination, root);
            }
            else {
                delete root; 
                return nullptr;
            }
        }

       
        parentMove = root;
        Node* movedFromLeft = movefile(root->left, currentName, currentPath, destinationName);
        if (movedFromLeft != nullptr) {
            return movedFromLeft;
        }

        parentMove = root;
        return movefile(root->right, currentName, currentPath, destinationName);
    }


	// able to copy and move file and directories
	void CopyandMove() {
        string namee,pathee,where;
        cout << " enter current file name :";
        cin >> namee;
        cout << " enter current file path :";
        cin >> pathee;
        cout << " enter destination file name :";
        cin >> where;
        cout << "\n1.For coping file\n2. for moving file";
        int cp = 0;
        cin >> cp;
        if(cp==1)
        copyfile(root, namee, pathee, where);
        else if(cp==2)
        movefile(root, namee, pathee, where);
        else {
            cout << "invalid!\n";
        }

	}











    void mergeDirectories(Node* sourceRoot, Node* destinationRoot) {
        if (sourceRoot == nullptr || destinationRoot == nullptr) {
            cout << "One of the directories is empty, cannot merge." << endl;
            return;
        }

        queue<Node*> q;
        q.push(sourceRoot);

        while (!q.empty()) {
            Node* currentNode = q.front();
            q.pop();

           
            if (currentNode != sourceRoot) {
                // Create a copy of the current node
                Node* newNode = new Node(currentNode->path, currentNode->name, currentNode->type);

               
                insertInSpot(destinationRoot, newNode);
            }

            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }
    }

    // Function to call mergeDirectories from the public interface
    void mergingDirectories() {
        string sourceName, destinationName;
        cout << "Enter the name of the source directory to merge: ";
        cin >> sourceName;
        cout << "Enter the name of the destination directory to merge into: ";
        cin >> destinationName;

        Node* sourceRoot = find_file(root, sourceName);
        Node* destinationRoot = find_file(root, destinationName);

        if (sourceRoot == nullptr || destinationRoot == nullptr) {
            cout << "Source or destination directory not found." << endl;
            return;
        }

        mergeDirectories(sourceRoot, destinationRoot);
    }

	





    void exportTreeFile(Node* root, ofstream& outFile) {
        if (root == nullptr) {
            return;
        }

        // Write node data to file
        outFile << root->path << "," << root->name << "," << root->type << endl;

        // Recursively export left and right subtrees
        exportTreeFile(root->left, outFile);
        exportTreeFile(root->right, outFile);
    }

    void exportToFile() {
        ofstream outFile("directoryTree.txt");
        if (!outFile.is_open()) {
            cout << "Error opening file for export." << endl;
            return;
        }

        exportTreeFile(root, outFile);
        outFile.close();
        cout << "Directory tree exported successfully." << endl;
    }



    Node* importTreeFile(ifstream& inFile) {
        string line;
        if (!getline(inFile, line)) {
            return nullptr;  // End of file or error
        }

        stringstream ss(line);
        string path, name, type;
        getline(ss, path, ',');
        getline(ss, name, ',');
        getline(ss, type);

        Node* node = new Node(path, name, type);
        node->left = importTreeFile(inFile);  // Import left subtree
        node->right = importTreeFile(inFile); // Import right subtree

        return node;
    }

    void importFromFile() {
        ifstream inFile("directoryTree.txt");
        if (!inFile.is_open()) {
            cout << "Error opening file for import." << endl;
            return;
        }

        root = importTreeFile(inFile);
        inFile.close();
        cout << "Directory tree imported successfully." << endl;
    }


};

