// system.h
// Module to manage files and commands
#ifndef SYSTEM_H_
#define SYSTEM_H_

// Buffer maxed size
#define BUFFER_MAX_LENGTH 1024

// Run the given Command
void System_runCommand(char* command);

// Read/write a file, given the file path + name and buffer
void System_readFile(char* fileName, char* buffer);
void System_writeFile(char* fileName, char* buffer);

#endif