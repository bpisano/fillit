#fillit

Here is the complete fillit project. It is designed to pass all the [42FileChecker](https://github.com/jgigault/42FileChecker) unit test.

#How does it works ?
Fillit is designed to takes one file in parameter containing from 0 to 26 [tetriminos](https://fr.wikipedia.org/wiki/Tétromino). The file should only contain "#", "." and "\n" characters.
Fillit will first verify the input (called **Verification** step), build a model that will be used for the solving algorithm (called **Build** step), adjust the tetriminos (called **Adjustment** step), then find the smaller square the tetriminos can fit in (called the **Solve** step).

#Steps
##Read
Simply call `char *read_file(char *file_name);` to read the content in **file_name**.

##Verify
Fillit will first verify that the input is correct by checking :

 1. if the input contain at least 20 characters
 2. if the input contain only `#`, `.` and `\n`
 3. if there is exactly one `\n` between 2 tetriminos model

This step calls `int input_is_valid(char *str);` to determine if the input is in the correct format.

##Build
This step is used to convert the input to a **t_tetri** structure that contains a 2D array of characters that represent a tetrimino and a *x*, *y*, *width* and *height* property.
Here is how a t_tetri is declared :

    typedef struct	s_tetri
    {
    	char		**tetri;
    	int			width;
    	int			height;
    }				t_tetri;

This step calls `t_tetri **build_model(char *str);` to build a list of **t_tetri**. It takes in argument the content of the file read by `read_file`.

##Adjustment
This step setup the *width* and *height* property of each tetrimino. It also center it up left.
This step calls `void adjust(t_tetri **model);` to adjust the model.
