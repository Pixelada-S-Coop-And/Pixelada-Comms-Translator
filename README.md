pixelada Comms Translator
========

Pixelada Comms Translator is a C++ application to take/send tags from/to industrial automation stations (for now, only through modbus TCP/IP communications, but it could use all formats supported by the [pvbrowser](http://pvbrowser.de) framework) and store them in a database, with the aim to share it to others systems as a simple Ms Windows OPC communication bridge.

This is intended for old Factorylink SCADA's software, already used in Industry.

I could also offer a REST api in future. 

This project is marked as the Industrial Electronics Engineering Degree final project of the Pixelada's member, [Joaquín Cuéllar](https://github.com/gentooza).

## Features

+ It's configurable via easy XML files, where edit Database type, topology, communications,tag, etc.
+ Database support (trough QT)
    - sqlite3
    - MySQL
+ Industrial communications
    - MODBUS TCP/IP
+ Easy integration in pvbrowser SCADA code, or other custom projects for visualization

## Dependencies

+ It's based in [pvbrowser](http://pvbrowser.de) libs, so have it installed is required.
+ QT 5 and it's drivers for databases. (MySQL, SQLite3)
    - from ubuntu xenial (16.04) to jammy (22.04)  for QT5: ``` sudo apt-get install qt5-default```
    - from ubuntu xenial (16.04) to jammy (22.04) for QT5: ``` sudo apt-get install libqt5sql5-mysql libqt5sql5-sqlite ```
+ Use of [gStools](https://github.com/gentooza/gStools) for tags conversions (already included in /lib folder as a submodule)
+ Use of [pugiXML](https://github.com/zeux/pugixml) for configurations files (already inluded in /lib folder, v1.7 as source code)

## Docs

Inside the docs folder you'll find documentation about installing, setting, etc.

+ [installing pixelada-comms-translator](docs/installing.md)
+ [configuring pixelada-comms-translator](docs/configuring.md)


## Contact

mail to: joaquin (at) pixelada (dot) org

## TODO/ROADMAP

[roadmap](./ROADMAP.md)

## Changelog

[changelog](./CHANGELOG.md)

## Copyright

Copyright 2022, Pixelada S. Coop. And. <info (at) pixelada (dot) org>

## License

```
Pixelada Comms Translator is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Pixelada Comms Translator is distributed in the hope that it will 
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Pixelada Comms Translator.  
If not, see <https://www.gnu.org/licenses/>.
```
