## Introduction 

`InternalHack` is a DLL hack for the [Assault Cube](https://assault.cubers.net/). 
`InternalHack` has to be injected into the game's process. From there it creates a console, givning the user options to activate hack or deactivate the hack. 

Currently the hack only changes ammunition (it's a proof of concept currently).

## Operation system, project, etc.

- IDE: Visual Studio 2019 (x86 project).
- OS: Windows 10, version 1909.

## Setup

1. Compile the source code
2. Run it one time - a folder and a `config.ini` file should be created on your desktop.
3. Navigate to `Desktop/Injector/config.ini`.
4. Fill in info about the offsets to the ammunition value (currently `Ammunition=0x10F4F4, 0x150`)

## Snapshots

### Successful injection

<img src="https://github.com/christianshub/DLL-Injector/blob/master/Snapshots/Success.png" height="200" width="600">

### Failed injection: No target process open

<img src="https://github.com/christianshub/DLL-Injector/blob/master/Snapshots/Fail1.png" height="200" width="600">

### Failed injection: No target name in config.ini:

<img src="https://github.com/christianshub/DLL-Injector/blob/master/Snapshots/Fail2.png" height="200" width="600">


### Credits

- Guided hacking (pointer chain function): https://guidedhacking.com/threads/finddmaaddy-c-multilevel-pointer-function.6292/
