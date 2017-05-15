#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;


void run (string filename){
	string command = "start powershell.exe ";
	command += filename;

	system(command.c_str());
}
bool vaccinateExists(string file){
	ifstream t(file);
	return t.is_open();
}
int main (int argc, char *argv[]){
	/*
	    static const char alphanum[] ={
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"

    */
    string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string scText[] = {
		"Set-SmbServerConfiguration -EnableSMB1Protocol $false -Force\n",
		"sls EnableSMB1Protocol Get-SmbServerConfiguration -ca \n"
	};

	//generate a file name to prevent selective exploits.
	string filename = "";
	for (int i = 0; i < 15;  i++){
		filename += alphanum[rand % (sizeof (alphanum) -1)];
	}
	filename+=".ps1";
	//ofsteam create shit
	ofstream script (filename.c_str());


	script << scText[0];
	script << scText[1];

	system ("start powershell.exe Set-ExecutionPolicy RemoteSigned \n");
	run(filename.c_str());
	return 0;
}