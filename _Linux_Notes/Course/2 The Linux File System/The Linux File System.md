## Índice
- [[#Intro]]
	- [[#Linux File System Structure]]
		- [[#1. Logical File System]]
		- [[#2. Virtual File System (VFS)]]
		- [[#3. Physical File System]]
	- [[#Characteristics of a File System]]

---
## Intro

> [!info] Source:
> https://www.geeksforgeeks.org/linux-unix/linux-file-system/

The **Linux File System** is a structured method of storing and organizing data on a Linux machine. It arranges files in a hierarchical directory format starting from the root directory `\`.
- All files and directories in Linux originate from a single root directory `\`
- It follows a [[Linux File Hierarchy Structure|hierarchy]] tree structure, making navigation simple and logical.
- Different directories like `/home`, `/etc`, `/bin` and `/var` serve specific system purposes
- Linux supports multiple file system  types like `ext4`, `XFS`, `Btrfs`, each offering different features. 
### Linux File System Structure
The Linux file system architecture is organized into three important layers, each responsible for different functionalities. These layers work together to provide smooth file access, storage and management.

![the_architecture_of_a_file_system](https://media.geeksforgeeks.org/wp-content/uploads/20260112171619580125/the_architecture_of_a_file_system.webp "Click to enlarge")
#### 1. Logical File System
Ensures applications interact with files in a simple and consistent way, without worrying about storage details.
- Acts as the interface between user applications and the file system.
- Handles key operations like open, read, write and close.
- Provides security checks, such as permissions and file access control.
#### 2. Virtual File System (VFS)
Makes file operations uniform and compatible, regardless of the underlying file system format.
- Provides a common interface for different file systems (ext4, XFS, FAT32, NTFS, etc.).
- Allows Linux to use multiple file system types at the same time.
- Acts as an abstraction layer, hiding the internal complexities of each file system.
#### 3. Physical File System
Ensures reliable storage, error handling and low-level data management.
- Directly interacts with the hardware and disk storage.
- Manages data blocks, nodes and physical memory allocation.
- Responsible for writing data to the disk and retrieving it efficiently.

## Characteristics of a File System
A file system defines the structure, rules and methods for how data is organized, stored, accessed and managed on a storage device.
- **Space Management**: Manages block allocation, free-space tracking and fragmentation control to optimize storage efficiency.
- **Filename**: Enforces naming rules including character sets, length limits and case sensitivity for file identification.
- **Directory**: Implements hierarchical indexing structures to organize and locate files efficiently.
- **Metadata**: Stores file attributes such as ownership, permissions, timestamps, size and file type information.
- **Utilities**: Provides system-level operations for file creation, deletion, backup, recovery and access management.
- **Design**: Defines architectural limits and mechanisms that determine file system scalability, reliability and performance.