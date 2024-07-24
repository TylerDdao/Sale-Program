# Sale managing system

**Table of Content**
- [Introduction](https://github.com/TylerDdao/Sale-Program/tree/master?tab=readme-ov-file#introduction)
- [Purpose of Project]()
- [How to Install]()
- [How to use]()
  - [Config mode]()
    - [Add Item]()
    - [Remove Item]()
    - [Edit Item]()
    - [Search Item]()
    - [Print all Items]()
    - [Delete all Items]()
  - [Sale mode]()
 
- [Future development]()
- [License]()
   

## Introduction
Introducing the all-in-one Sale Manager program designed to streamline your sales process! This program offers two powerful modes: Config and Sale. In Config mode, take complete control over your menu.  Add, remove, edit, search, and even print any item with ease. When you're ready to start selling, switch to Sale mode. Here, you can add, remove, search, and print sales transactions.  For each confirmed sale, the system automatically generates a unique ID for easy tracking and reference.

## How to use
- To enter config mode, type `c` to command line and then the system will show options for config mode, allows you to take control completely your menu.
- Just like when you enter config mode, with sale mode, type `s` to command line.
- To quit the program safely, if you are in a mode, quit to the main first and then type `q` to save data and quit.
**If you don't following these processes, you data would not be saved which might lead to data lost.**

**Note: In case you are currently in a mode (not in main), you have to choose the option to return to main menu before you can switch to a different mode.**

### Config Mode
Config Mode has 7 options.
1. Add Item
2. Remove Item
3. Edit Item
4. Search Item
5. Print all Items
6. Delete all Items
7. Return to Main

#### Attributes of an item
An item has 3 attributes.  
`Name`, `ID`, and `Price`.
`Name` is a string value represents the name of item.  
`ID` is an unique string value of item for managing and reference.  
`Price` is a float value represents the price of item.
#### 1. Add Item
Before selling, you need item to sell, adding item is the feature to start with. System will ask user for attributes of the new item.
`Enter name: ` Enter name for the item.  
`Enter ID: ` Enter ID for the item. ID can be a string or number(For example: "AB0123" or "123456"). **Each item has an unique ID, new ID can not be match with any ID that already existed.**  
`Enter price: $` Enter price for the item. **Do not enter any non-number character except for "." in this input field. It could lead to unwanted problem.**  
After entering all essential value for the item, system will print out the item information again, and ask user to confirm before the item is added to the list.  
#### 2. Remove Item
This feature allows user to remove unwanted item from the menu.  
`Enter ID` Enter ID of the item you want to remove.  
If the ID existed, the item with that ID will be printed out, and then system will ask for confirmation from user before removing from the menu.  
#### 3. Edit Item
This feature is for changing `Name`, `ID`, and `Price` of existed item
`Enter ID: ` Enter ID of the item you want to change.  
`Enter new name: ` Enter new name of the item.  
`Enter new ID: ` Enter new ID of the item. **New ID has to be different from the current ID and any other IDs.**  
`Enter new price: $` Enter new price for the item.  
After all attributes are set, the system will print out new infomations of item, and ask for user's confirmation before changing.
#### 4. Search Item
This feature allows user to search for item by its ID. If ID is found, the system will print all infomation of the item.  
`Enter ID: ` Enter ID of the item you want to search for.  
#### 5. Print all Items
This feature doesn't require input from user, it will print all the items in menu.  
#### 6. Delete all Items
This feature will delete all items in menu. It provides 2 options, which are save data then delete or delete without saving.  
- If user choose save then delete option, system will ask for file name **file name has to include file format at the end (.txt/.bin/...).** then the system will ask for user's confirmation and then it will provide the name of file after saving process is done.
- if user choose delete without saving, system will send a warning and then ask for user's confirmation before deleting process.

### Sale Mode
Sale Mode has 6 options.  
1. New Sale
2. Remove Sale
3. Search Sale
4. Print all Sales
5. Delete all Sales
6. Return to Main
#### Attributes of a sale
A sale has 4 attributes.  
`ID`, `orders`, `total`, and `time`
`ID` is an auto-generated number of sale for managing and reference.  
`orders` is a list of item IDs for the sale.  
`total` is a total of price of items in orders list.  
`time` is time when the sale is added to the system.  
#### New Sale  
When you get a order from a customer, you need to add sale to the system.  
`Enter item ID: ` Enter item ID to add to sale.  
After item is added to sale, system will ask if user wants to add more item. If not user needs to confirm before the sale is added to system and user receives sale ID.  
#### Remove Sale

## License
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
