#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#include "commandDeclaration.h"



int main() {
  //object specification
  

  //start

  if (logoOn != 1) {
    tuvuLogo();
  }


  cout << "~/TUVU> ";
  cin >> command;



  //command initiation
  if (command == "help") {
    help();
  }
	/*
  if (command == "ping") {
    ping();
  }
	*/
	/*
  if (command == "signin") {
    signIn();
  }
	*/
  if (command == "quit") {
    quit();
  }
  if (command == "changelog") {
    changeLog();
  }
  if (command == "logo") {
    tuvuLogo();
  }
  if (command == "devmode") {
    devMode();
  }
  if (command == "file") {
    fileCommand();
  }
	if (command == "credits") {
		credits();
	}
  


  else {
		cout << "your input '" << command << "' was not found as a valid command!" << endl;
    main();
  }

  return 0;
}



void help() {
  if (adminOn != 1) {
    cout  << "commands marked with an asterisk (*) are under work and might not work" << "help*" << endl << "ping*" << endl << "signin*" << endl << "quit" << endl << "changelog" << endl << "logo" << endl << "devmode*" << endl << "file" << endl;
    main();
  } else {

  }
  


}


/*
void ping() {
  if (adminOn == 1) {
//    cout << "enter IP address" << endl << "> ";
    cin >> ip;
    pingAddOn();
//    int pingCommand = system(ip.str());
    if (pingCommand == 0) {
      cout << "fail" << endl;
    } else {
      cout << "success" << endl;
    }
} else {
  cout << "pong!" << endl;
}
  main();
}
*/

/*
void signIn() {
  if (adminOn == 1) {
    cout << "Already signed in";
  } else {
    cout << "USER: ";
    cin >> userName;
    cout << "PASSWORD: ";
    cin >> passWord;
    if (userName == mySecret) {
    if (passWord == mySecret1) {
      cout << "Welcome, Admin" << endl;
      adminOn = 1;
      main();
    }
    } else {
     cout << "Wrong sign in, type 'signin' to try again" << endl;
      main();
    }
  } 
}
*/
  

void writeFile() {
  
  cout << "filename" << endl << "> ";
  cin >> fileName;
  cout << "file content (end with writing with 'endFileWrite'):" << endl;
  cin.ignore();
	while(getline(cin, fileContent)) {
		if (fileContent == "endFileWrite\n")
			break;

		fileContent += fileContent;
	}
  ofstream file(fileName);
  file << fileContent;
  file.close();
  cout << "file written successfully" << endl;
  main();
};


void readFile() {
  cout << "file name? (include extension)" << endl << "> ";
  cin >> fileName;
  cout << "file contents: " << endl << "-----" << endl << endl;
  ifstream readFile(fileName);
  while (getline (readFile, fileContent)) {
    cout << fileContent << endl;
  }
  readFile.close();
  cout << endl << "-----" << endl << "end of file contents" << endl;
  main();
};

void quit() {
  cout << "programme terminated" << endl;
  exit(0);
}

void changeLog() {
  cout << "Changelog:" << endl << "-----" << endl << endl;
  ifstream readFile("changeLog.txt");
  while (getline (readFile, fileContent)) {
    cout << fileContent << endl;
  }
  readFile.close();
  cout << endl << "-----" << endl;
  main();
}

void tuvuLogo() {
  cout << "Welcome to... " << endl << endl << "█████████████████████████████████████████████████████████████" << endl << "█░░░░░░░░░░░░░░█░░░░░░██░░░░░░█░░░░░░██░░░░░░█░░░░░░██░░░░░░█" << endl << "█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█" << endl << "█░░░░░░▄▀░░░░░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█" << endl << "█████░░▄▀░░█████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█" << endl << "█████░░▄▀░░█████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█" << endl << "█████░░▄▀░░█████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█" << endl << "█████░░▄▀░░█████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█" << endl << "█████░░▄▀░░█████░░▄▀░░██░░▄▀░░█░░▄▀▄▀░░▄▀▄▀░░█░░▄▀░░██░░▄▀░░█" << endl << "█████░░▄▀░░█████░░▄▀░░░░░░▄▀░░█░░░░▄▀▄▀▄▀░░░░█░░▄▀░░░░░░▄▀░░█" << endl << "█████░░▄▀░░█████░░▄▀▄▀▄▀▄▀▄▀░░███░░░░▄▀░░░░███░░▄▀▄▀▄▀▄▀▄▀░░█" << endl << "█████░░░░░░█████░░░░░░░░░░░░░░█████░░░░░░█████░░░░░░░░░░░░░░█" << endl << "█████████████████████████████████████████████████████████████" << endl << endl << "type 'help' to begin" << endl << endl;
  logoOn = 1;
  main();
}


void devMode() {
adminOn = 1;
cout << "dev mode activated" << endl;

main();
}


void pingAddOn() {
  ip = "ping -c1 -s1 " + ip + " > /dev/null 2>&1";
}

void fileCommand() {
  cout << "> ";
  cin >> confirm;

  if (confirm == "write" || confirm == "edit") {
    writeFile();
  }
  if (confirm == "read") {
    readFile();
  } else {
    cout << "arguments are: " << endl << "write" << endl << "  alias: edit" << endl << "read" << endl;
  }

  main();
}

void credits() {
	cout << "credits:" << endl;
	cout << "Programmers:" << endl;
	cout << "Torcenta" << endl;
	main();
}


/*
void deleteFile() {
  cout << "file name: " << endl << "> ";
  cin >> fileName;
  if(remove(fileName.str()) != 0 )
    perror("Error deleting file");
  else
    puts("File successfully deleted");
}
*/



//MAKE SURE TO PUT THE COMMAND IN THE main() FUNCTION!!1!