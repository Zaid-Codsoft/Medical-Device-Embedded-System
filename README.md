# Medical-Device-Embedded-System(Console Based system)
Developing a File Directory Tree Shell for Medical Device Embedded System  Design and implement a File Directory Tree Shell tailored for a small, embedded operaƟng system used in medical devices. This shell will enable the management of files and directories, with a focus on efficiency and resource optimization.
Task DescripƟon:
You have been enlisted by a company specializing in medical device embedded systems. They are
developing a new medical device that necessitates a compact operaƟng system for debugging purposes.
This operaƟng system will exclusively manage files categorized as paƟent data, device seƫngs, and logs.
Your mission is to create a File Directory Tree Shell customized for their specific needs.
NOTE: YOU MAY RESTIRCT THIS TO BINARY TREE AND MAINTAIN ONLY PATIENT DATA AND LOGS.

I. File Directory Structure

1. Implement a tree data structure to represent files and directories within the operaƟng system.
Each node in the tree should have the following aƩributes:
• Name: The name of the file or directory.
• Path: The full path to the file or directory.
• Type: IndicaƟon of whether the node is a directory or file.
• Children: A list of child nodes.
2. Develop a funcƟon to create a new directory within the tree. Users should be able to specify the
directory name.
3. Create a funcƟon to create new files within the tree, allowing users to specify the name, type
(e.g., txt, pdf), and complete path.

II. Core FuncƟonality 

4. Implement funcƟonaliƟes for:
• LisƟng the file directory tree in a tree view (level order).
• Merging directories, combining the contents of a given subtree or tree.
• DeleƟng and renaming files and directories.
• Searching for files and directories by name or content.
• Copying and moving files and directories between different locaƟons.
• ExporƟng and imporƟng the file directory tree to and from a file.

III. Error Handling 

5. Implement comprehensive error handling for common scenarios, including but not limited to
aƩempƟng to delete non-empty directories, moving to non-existent locaƟons, and other potenƟal piƞalls.
During merging or moving, check for duplicates as well.
