# TempMeas
EDDCH1602, Hands-on Session "Bare Metal Programming for Devices with C++"

## How to build (for Eclipse)
  1. Create a directory where your Eclipse Workspace will be stored and where this project shall be cloned into. E.g. `C:\git\pio-prj`
  2. Clone this repository recursively into the folder ou created before, `git clone --recursive git@github.com:ERNICommunity/TempMeas.git`
  3. Open a command shell in the just cloned project folder, i.e in `C:\git\pio-prj\TempMeas`
  4. Run the command `pio init -b huzzah --ide eclipse`
  5. Run the command `pio run`

## Open project in Eclipse CDT
  6. Open Eclipse CDT, as workspace choose the folder you created before, i.e `C:\git\pio-prj`
  7. Import the project with File->Import->General->Existing Projects into Workspace, choose the `TempMeas` (i.e `C:\git\pio-prj\TempMeas`)