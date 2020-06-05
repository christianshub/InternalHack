## Introduction 

`InternalHack` is a DLL hack for the [Assault Cube](https://assault.cubers.net/). Currently the hack only changes ammunition (it's a proof of concept currently).
`InternalHack` has to be injected into the game's process. From there it creates a console, givning the user options to activate hack or deactivate the hack. 

Console options once injected into a game:

<img src="https://github.com/christianshub/InternalHack/blob/master/Snapshots/injected.png" height="100" width="600">


## Operation system, project, etc.

- IDE: Visual Studio 2019 (x86 project).
- OS: Windows 10, version 1909.

## Setup

1. Compile the source code
2. Run it one time - a folder and a `config.ini` file should be created on your desktop.
3. Navigate to `Desktop/Hack/config.ini`.
4. Fill in info about the offsets to the ammunition value (currently `Ammunition=0x10F4F4, 0x150`)

## Snapshots

### Before

<img src="https://github.com/christianshub/InternalHack/blob/master/Snapshots/BeforeHack.png" height="200" width="600">

### After

<img src="https://github.com/christianshub/InternalHack/blob/master/Snapshots/AfterHack.png" height="200" width="600">


### References


- [Guided hacking](https://guidedhacking.com/threads/finddmaaddy-c-multilevel-pointer-function.6292/) (pointer chain function)
