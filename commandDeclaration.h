//commands
void help();
void ping();
void signIn();
void writeFile();
void readFile();
void quit();
void changeLog();
void tuvuLogo();
int main();
void devMode();
void pingAddOn();
void fileCommand();
void deleteFile();
void credits();

//secrets
char* mySecret = getenv("USER");
char* mySecret1 = getenv("PASSWORD");

//variables
string userName;
string passWord;
int adminOn;
string command;
string fileName;
string fileContent;
string confirm;
string ip;
int logoOn;
int pingCommand;
string input;
string line;