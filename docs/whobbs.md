# RDB: a Relational Database Management System

WORKING DRAFT 
Walter V. Hobbs <hobbs@rand.org>

## Summary
RDB is a fast, portable, relational database management system without arbitrary limits, (other than memory and processor speed) that runs under, and interacts with, the UNIX Operating system.

It uses the Operator/Stream DBMS paradigm described in "Unix Review", March, 1991, page 24, entitled "A 4GL Language". There are a number of "operators" that each perform a unique function on the data. The "stream" is suplied by the UNIX Input/Output redirection mechanism. Therefore each operator processes some data and then passes it along to the next operator via the UNIX pipe function. This is very efficient as UNIX pipes are implemented in memory (at least in versions of UNIX at RAND). RDB is compliant with the "Relational Model".

The data is contained in regular UNIX ACSII files, and so can be manipulated by regular UNIX utilities, e.g. ls, wc, mv, cp, cat, more, less, editors like the RAND editor 'e', head, RCS, etc.

The form of each file of data is that of a relation, or table, with rows and columns of information.

To extract information, a file of data is fed to one or more "operators" via the UNIX Input/Output redirection mechanism.

There are also programs to generate reports, and to generate, modify, and validate the data.

## Documention
1. Preface
1. Acknowledgements
1. Introduction
1. Data (RDBtable)
1. Operators
1. Extracting Information from RDBTables
1. Generating or Modifing RDBTables
1. Conversion of External Data Into RDBTables
1. Data Access Control
1. Fast Access Methods
1. Limits, A Few Minor Ones
1. References
1. Examples of Perl Expressions and Statements

## Preface
This working draft describes, and provides instructions for the use of, the RDB system as it currently exists at RAND. The RDB system is currently used by a number of projects at RAND, however the development is not finished and there are plans to make enhancements and extensions as required. Accordingly, revisions of this document will be produced.

The preparation of this research document was sponsored through RAND's three federally funded research and development centers - the National Defense Research Institute (sponsored by the Office of the Secretary of Defense and the Joint Staff), the Arroyo Center (sponsored by the U.S. Army), and Project AIR FORCE (sponsored by the U.S. Air Force).

It should be noted that the development of the computer code comprising the RDB system was not done under any RAND contract and was accomplished on non-RAND time as a personal computer science project of the author.

## Acknowledgements
I would like to thank the following people for their ideas and suggestions on the implementation and improvement of the RDB system, as well as some needed checkout of obscure bugs in the code:

Chuck Bush
Don Emerson
Judy Lender
Roy Gates
Rae Starr

## Introduction
A good question one could ask is "With all the relational database management systems available today, why do we need another one?" There are five reasons. They are:

RDB is easy to use by non-computer people. The concept is straight forward and logical. To select rows of data, the 'row' operator is used; to select columns of data, the 'column' operator is used.
The data is highly portable to and from other types of machines, like Macintoshes or MSDOS computers.
The system will run on any UNIX machine (that has the PERL Programming Language).
The system can work on intermediate data, which will later be put into a commercial RDBMS, like INGRES.
RDB essentially has no arbitrary limits, and can work where INGRES can't. For example there is no limit on data field size, the number of columns, or file size.
A more through discussion of why this type of relational database structure makes sense is found in the book, "UNIX Relational Database Management", Reference #2.

It is assumed that the reader has at least a minimum knowledge of the UNIX Operating System, including knowledge of Input/Outout redirection (e.g., STDIN, STDOUT, pipes).

The RDB system was implemented in the PERL programming language on a SUN Sparc I computer.

This document presents information in the following order: The DATA section describes the structure of the data, with examples. There is a general discussion about operators in the section on OPERATORS, followed by several sub-sections, one for each operator in alphabetic order. Each has detailed instructions for use, and examples. There are sections describing selection of information using multiple operators, producing reports, and generating new rdbtables (data files in RDB format).

## Data (rdbtable)
The data is contained in regular UNIX, ASCII files and therefore can be manipulated by regular UNIX utilities, e.g. grep, ls, wc, mv, cp, cat, more, less, head, RCS, and editors like the RAND editor 'e', vi, etc. A good way to view the data of course, would be to use the RDB operator that prints such datafiles 'ptbl'.

The relation, or table structure is achieved by separating the columns with ASCII TAB characters, and terminating the rows with ASCII NEWLINE characters. That is, each row of data in a file contains the data values (a data field) separated by TAB characters and terminated with a NEWLINE character. Therefore a fundamental rule is that data values must NOT contain TAB characters.

The first section of the file, called the header, contains the file structure information used by the operators. The header also contains optional embedded documentation relating to the entire datafile (table documentation) and/or each data column (column documentation). The rest of the file, called the body, contains the actual data values. A file of data, so structured, is said to be an 'rdbtable'.

The header consists of two or more lines. There is an optional number (zero or more) of lines of table documentation followed by exactally two lines that contain the structure information: the column name row and the column definition row. The table documentation lines start with either a sharp sign (#) followed by a space character, or one or more space characters followed by a sharp sign (#). The rest of each line may contain any documentation desired. Note that the table documentation lines are the only lines in an rdbtable that are not required to conform to the table structure defined above. The fields in the column name row contain the names of each column. The fields in the column definition row contain the data definitions and optional column documentation for each column.

The column names are case sensitive, i.e. 'COUNT' is different from 'Count'. The guideline for characters that may be used in column names is that alphabetic, numeric, and non-alphanumeric characters that are not special to the UNIX shell are good choices. Column names must include at least one alphabetic character. It is highly recommended (but not required) that column names start with an alphabetic or numeric character.

Non-alphanumeric characters that are acceptable in column names are the percent sign (%) colon (:) at sign (@) equals (=) comma (,) and dot (.). The sharp sign (#) underscore (\_) and dash (-) characters may also be used but they must not be the first character in a column name. The TAB character must never be used in column names, nor should internal spaces or UNIX I/O redirection characters (<,>,|) be used.

The data definitions include column width, data type, and justification. The column width must be explicitly specified; the others are optional and are frequently specified by default.

The data definitions are specified by adjacent characters in a single word. The width of each field is specified by a numeric count. The type of data is "string", "numeric", or "month". The types are specified by an 'S', 'N', or 'M' respectively, and the default is type string. Printout justification is 'left', or 'right', and is specified by an '<' or '>' character respectively. If not specified, data types string and month will be left justified and type numeric will be right justified.

Note that column width is used primarily by the operator 'ptbl' and in no way limits the actual data size. It is not an error if some actual data in a column is wider than the defined width; a listing produced with 'ptbl' may be out of alignment however.

The optional documentation for each column follows the data definition word in the field. There must be one or more space characters after the data definition word and before the column documentation; the column documentation may be as long as necessary. Note that the data definition and the optional column documentation are contained in a single field in the row.

If the column name and/or column definition rows contain much information and/or column documentation they can become long and confusing to read. However the operators 'valid' and 'headchg' have options to print the header contents as a 'template' file, an organized list of information about the header.

A sample rdbtable (named sample) that will be used in later examples is shown in Table 1. The picture in Table 1 is for illustrative purposes; what the file would actually look like is shown in Table 2, where a TAB character is represented by '<T>' and a NEWLINE character is represented by '<N>'.

It is important to note that only actual data is stored in the data fields, with no leading or trailing space characters. This fact can (and usually does) have a major effect on the size of the resulting datafiles (rdbtables) compared to data stored in "fixed field width" systems. The datafiles in RDB are almost always smaller, sometimes dramatically smaller.

                                Table 1
                           RDBTABLE (SAMPLE)

        # Table documentation lines. These describe and
        # identify the rdbtable contents.
        # They may be read by many normal UNIX utilities,
        # which is useful to easily identify a file.
        # May also contain RCS or SCCS control information.
        NAME    COUNT   TYP     AMT     OTHER   RIGHT
        6       5N      3       5N      8       8>
        Bush    44      A       133     Another This
        Hansen  44      A       23      One     Is
        Jones   77      X       77      Here    On
        Perry   77      B       244     And     The
        Hart    77      D       1111    So      Right
        Holmes  65      D       1111    On      Edge

                                Table 2
                    RDBTABLE (SAMPLE) ACTUAL CONTENT

        # Table documentation lines. These describe and<N>
        # identify the rdbtable contents.<N>
        # They may be read by many normal UNIX utilities,<N>
        # which is useful to easily identify a file.<N>
        # May also contain RCS or SCCS control information.<N>
        NAME<T>COUNT<T>TYP<T>AMT<T>OTHER<T>RIGHT<N>
        6<T>5N<T>3<T>5N<T>8<T>8><N>
        Bush<T>44<T>A<T>133<T>Another<T>This<N>
        Hansen<T>44<T>A<T>23<T>One<T>Is<N>
        Jones<T>77<T>X<T>77<T>Here<T>On<N>
        Perry<T>77<T>B<T>244<T>And<T>The<N>
        Hart<T>77<T>D<T>1111<T>So<T>Right<N>
        Holmes<T>65<T>D<T>1111<T>On<T>Edge<N>

## Operators
The operators are separate program modules that each perform a unique function on the data. They can be grouped into data movers, report generators, and utilities.

The data movers are operators that extract or rearrange the data in some way. They each read an rdbtable via STDIN and write a rdbtable via STDOUT and so are frequently connected using the UNIX pipe function to form a larger task. Each operator in such a "pipeline" style of operation gets its input from the output of the previous operator in the "pipeline". The data movers include:

row - Selects rows based on arbitrary expressions.
column - Selects columns by name, outputs columns in listed order.
search - Selects rows based on a multi-column key of a sorted or indexed rdbtable.
sorttbl - Sorts a datafile by one or more columns.
jointbl - Natural or "Master/Detail" join of two rdbtables.
mergetbl - Merges two like rdbtables.
compute - Computes an arbitrary expression using column names.
uniqtbl - Makes an rdbtable unique on specified columns.
subtotal - Lists subtotals of specified columns.
The report generators each read an rdbtable via STDIN and produce a report on STDOUT, so when they are in a "pipeline" of operators they will be the operator at the end. The report generators are:

ptbl - Quick and easy printing of output formatted from information in the header.
reporttbl - Best form of output, with definable format.
summ - Summary/Statistical information about data values in an rdbtable.
The utilities are used for manipulating the structure and content of rdbtables and are generally used as separate tasks. The utilities are:

headchg - Generates and replaces (or removes) the header of an rdbtable.
dataent - An interactive capability for entering data into an rdbtable.
etbl - Uses an editor to allow modifications to an rdbtable.
valid - Verifies the structure of an rdbtable.
repair - Attempts to repair candidate RDB datafiles.
All operators take a '-help' option to show details of operation online. Following is a sub-section for each operator, in alphabetic order.

## Extracting Information from RDBTables
### GENERAL
The following shows some examples of how the system is usually used, which involves a combinations of operators. Using the rdbtable named 'sample' the command:

        column NAME OTHER TYP AMT < sample | sorttbl TYP AMT | ptbl
gives the output:
        NAME    OTHER     TYP     AMT
        ------  --------  ----  -----
        Hansen  One       A        23
        Bush    Another   A       133
        Perry   And       B       244
        Hart    So        D      1111
        Holmes  On        D      1111
        Jones   Here      X        77
Note that columns COUNT and RIGHT were excluded by the 'column' oper, and that the order of the selected columns was changed from that in the rdbtable. Of course to save the output in a file, (redirection of STDOUT into a file) something like the following is used:
        column ... < sample | sorttbl ... | ptbl > file.out
An example using the operator 'row' on the rdbtable sample is:
        row AMT lt 900 < sample | column NAME AMT TYP RIGHT |\
        sorttbl l NAME | ptbl
Note that the '\' character at the end of the first line of the above command is the signal to the UNIX shell that the command is continued on the next line. Here we select some rows using 'row', select some columns using 'column', sort what we have with 'sorttbl', and print with 'ptbl'. The output is:
        NAME      AMT  TYP      RIGHT
        ------  -----  ----  --------
        Bush      133  A         This
        Hansen     23  A           Is
        Jones      77  X           On
        Perry     244  B          The
### A REAL WORLD PROBLEM
The following shell script shows how the RDB operators and other UNIX utilities can be fitted together to solve a real world problem. The problem was to find out if the rows in a large rdbtable were unique over four columns. Since 'summ' will tell us whether the rows of an rdbtable are unique on a single column, we need to construct a temporary tdbtable.

To illustrate the solution on a small rdbtable, the script below works on an rdbtable like 'sample' but with some rows repeated. First the script selects four columns and adds a dummy column named 'uniq' (using 'column'). It then puts the combined values of the four columns into the dummy column (using 'compute'). Next it examines the value of the dummy column 'uniq' for uniquness (using 'summ') and then uses the UNIX command 'egrep' to show only the lines of interest, e.g. those lines that start with something other than a '1'.

        column < table.rdb  Unit  Day  Time  MSN  -a uniq 12 |\
        compute uniq = Unit . Day . Time . MSN |\
        summ  -cuu  uniq  |\
        egrep -v  '^  *1'
The output was like the following:
Rows: 9

Unique values for uniq: 6
       2 Jones77X77
       3 Perry77B244
meaning that there were (in this example) two rows that had duplicates over the four columns with one set of values, and three rows that had duplicate with another set of values.
ANOTHER REAL WORLD PROBLEM
This next one is a bit more complicated although very useful, and it does demonstrate the use of 'compute' using a newly created column. The idea is to make a summary of the data in rdbtable sample3 (from the section on 'etbl'). The command is:

        column name datatype -a nr 2 < sample3 |\
        compute nr = '++$x' |\
        sorttbl datatype name | reporttbl sum.frm
Note that 'column' selects the two columns on which to make the summary and adds a new (null) column 'nr'. Then 'compute' puts data into the new column by using the PERL expression shown. The expression '++$x' merely increments itself by one each time it is evaluated, an easy way to get an increasing number. Finally 'sorttbl' sorts the newly created rdbtable and it is then printed with 'reporttbl' using the form file 'sum.frm'.
                                Table 19

                          FORM FILE (SUM.FRM)

format top =
                                              @<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                _date_
            Sample Three Database Summary by Datatype

       Datatype  Nr  Name
       --------  --  -----------------------------------------
.
format =
       @>>>>>>>  @>  @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
       datatype  nr  name
.


                                Table 20

                        DATABASE SUMMARY EXAMPLE

                                              Wed Dec  4 21:23:20 PST 1991
            Sample Three Database Summary by Datatype

       Datatype  Nr  Name
       --------  --  -----------------------------------------
            ABC   5  ABC Duplicate
            ABC   4  ABC Original
            ABC   8  LAF-S Air Floating Model
            ATO   3  ATO (Air Tasking Orders) Original
            ATO   6  ATO Number 2222-11
            BDA   1  ACAS (Air Combat Assessment)
            BDA   2  ACAS (Air Combat Assessment) BDA Sorties
            BDA   7  BDA Supplement number 17
The form file is shown in Table 19 and the output in Table 20.

## Generating or Modifing RDBTables
### GENERATING NEW RDBTABLES
Any editor may be used to construct or modify an rdbtable, since it is a regular UNIX file, and this 'direct editing' method is occasionally used, especially for small amounts of data. However, avoid using an editor that destroys TAB characters, like the RAND 'e' editor.

To generate a new rdbtable the best plan (and usually the safest one) is to first generate a template file, then convert it to rdbtable format and add the rows of data. Any convenient editor may be used to generate a template file. To convert it to an rdbtable the command 'headchg -gen' may be used, which will produce an empty rdbtable. Next use the operator 'etbl' to edit in rows of data.

An alternate method is to generate a template file with an editor and then use the command 'dataent -init template_file' to enter the rows of data.

A typical template file is shown below:

# These are lines of table documentation. They can be of any length,
# and any number of such lines may exist.
# Each line must start correctly, e.g with "# " or " #". Any number of
# space characters may preceed the sharp sign in the second case above.
0       Name  24   Name of item
1       Type   1   Type: 1,2,3,7,9,A,B,X
2      Count   3N  Number of items
3          K   1   Constant modifier
4        SS7   2   Special status for type 7
5       Size  12N  In Kilobytes
It makes sense to have all significant or critical documentation about an rdbtable embedded in the rdbtable, rather than in some other place. The above template file contains the usual elements to describe a table of six columns: table documentation (the comment lines that each start with a sharp sign '#'), index number (the first number on each of the column lines), column name ("Name", "Type", "Count", ...), column definition ("24", "1", "3N", ...), and column documentation for each column (the text at the end of each column line).

Note that the index number, column name, and column definition all consist of contiguous characters, each forming a word separated by whitespace. Also note that there is one or more space characters after the column definition and before the column documentation. That is, the column documentation starts with the fourth word on the line.

When the template file is converted into an rdbtable, all documentation will remain in the header (although the column documentation may be hard to read if there are many columns). At any time the entire header, including documentation, can be viewed by using the command 'valid -templ < rdbtable' (or 'headchg -templ < rdbtable). The output from either command will be essentially like the above example.

### Modifying Existing RDBtables
Basically there are three ways to modify an existing rdbtable: Use 'dataent', 'etbl', or 'mergetbl'. The operator 'dataent' can only add new rows of data, and they are added at the end of the existing table. Therefore the table may need sorting after the modification process is done. The following command might be used to update an rdbtable using 'dataent':
    dataent  rdbtable
The operator 'etbl' can be used to add new rows, change existing rows, or delete existing rows of data in an rdbtable. To modify an rdbtable 'etbl' can be used in either column or list form. The choice of form to use depends somewhat on the structure of the rdbtable. If the rdbtable has several columns of relatively narrow data (that will all fit in the width of the current window or terminal) and also several very wide columns (none of which will fit) and changes need to be made to some of the narrow columns, then it makes sense to use 'etbl' on the desired narrow columns in 'column' form, as in:

    etbl  table  narrow_cola  narrow_colb  ...
If changes need to be made to some of the wide columns then use 'etbl' in 'list' form on the wide columns, plus any key columns necessary, as in:
    etbl  -list  table  control_col  ...  wide_cola  wide_colb  ...
After editing an rdbtable it is always recommended that the structure of the rdbtable be checked with the operator 'valid'. If there are data values that are longer than the defined column width, use the command 'valid -n' to avoid many warning messages.

The 'mergetbl' process actually involves other operators like 'search', and 'etbl', and works only when the existing rdbtable is sorted on one or more columns (which is a fairly common case). The process includes selecting rows from an existing sorted rdbtable (using 'search') into a small rdbtable which is easy to edit (using 'etbl') and then combining the two rdbtables again (using 'mergetbl'). Since 'etbl' is used modifications may include changes, additions, or delitions of rows. Also note that 'mergetbl' keeps the final table in sort order.

The difference is that 'search' is much faster than 'row' or 'etbl', the editing is done on a table of conveniently small size, and that the 'mergetbl' operation can be done in the background. Remember that whether one uses 'mergetbl' or 'etbl', putting the data back together after editing requires the entire original table to be passed, which can take some time if the original rdbtable is large.

### CONCATENATING RDBTABLES
The need to concatenate rdbtables comes up every so often and although it is simple to do it may not be obvious. The UNIX 'cat' command can not be used as it would result in duplicating the header and thus make an invalid rdbtable. And of course, only rdbtables with the same header should be concatenated, otherwise an invalid rdbtable would result (in this case it could be a gross inconsistency if the number of columns were different). If we have two rdbtables, TABA and TABB, then to concatenate TABB onto the end of TABA we use the command:
        headchg -del < TABB >> TABA
Note that this avoids duplicating the header. Note also that in this case the operator 'headchg' does not use a template file.
Note also that the operator 'mergetbl' may be used to merge two like rdbtables based on a key of one or more columns. In this case however the two rdbtables must be sorted on the key.

## Conversion of External Data Into RDBTables
The best method I have found to convert data in files that were received from an external source is to use the PERL Programming Language. A typical PERL script for such a conversion from a file of fixed column data is shown in Table 21. The last two lines do most of the work. Note that this process converts the data into an rdbtable body only; the rdbtable header must still be generated manually.

The easiest and best way to accomplish the above is to first construct a template file from known or observed information in the external data file, then generate the header using 'headchg -gen'. Then run the PERL script appending the output to the header file. Then run 'valid' to make sure everything went allright.

                                Table 21

                    PERL SCRIPT FOR DATA CONVERSION
'''
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#! /usr/bin/perl
$templ = "A6 A12 x A5 x6 A18 A17 x A38 x4 A2 x A x2 A15 x3 A6 A4 x2" .
    " A2 x4 A5 x A3 A3 A4 x26 A12 A12 A12 A29 x7 A3 A3 x6 A6 A6 A8" .
    " A4 A3 x3 A3 x3 A8 x10 A2 x4 A12 x138 A6 x66 A24 A36 A12 x6" .
    " A6 A6 x6 A6 A24 A12 x50 A42 A42 A42 x34 A12 A12 x186 A6" ;
$0 =~ s-.*/-- ;
$HelpInfo = <<EOH ;
Usage:$0  [options]  file

    Strip out and reform an 'external' data file into an rdbtable.

Options:
 -help - Print this help information.

Strips out the first 46 fields from an 'external' data file and
reformats it into 'rdbtable' format (TAB delimited with NEWLINE at end).
Output is on STDOUT.
EOH
while ( $ARGV[0] =~ /^-/ ) {                            # Get args
    $_ = shift ;
    if( /-h.*/ ){ die $HelpInfo ; }
    die  "Bad arg: $_\n", $HelpInfo ;
}
while(<>){
    @a = unpack( $templ, $_ );
    print join( "\t", @a), "\n" ;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
'''

## Data Access Control
### GENERAL
Since rdbtables are regular UNIX files, we have so far found no need to implement, and have the associated overhead of, general data access controls in RDB. Setting the UNIX permissions on files or directory has proven very useful and effective. This is another example of how the RDB system works "with" UNIX, not in addition to it, e.g. not duplicating UNIX functions.

The Revision Control System (RCS) is one of the best configuration management tools available and is in use here at RAND for version control of many types of files, including rdbtables. The operator 'etbl' will automatically check out an rdbtable for editing, and then check the new version back into RCS. Other operators can utilize rdbtables that are under RCS control by using commands like:

        co  -p  table  |  row  ...  |  column  ...  |  ptbl
Note that this checks out an rdbtable, sends it to 'row', then to 'column', and finally prints the data with 'ptbl'. In general, any series of commands necessary can be constructed to do a given task even if the rdbtables are checked into RCS.

### WRITE CONCURRENCY CONTROL
When either of the two utility operators 'etbl' or 'dataent' is used (which modify an rdbtable in place) there could be a possibility of silmultaneous wrting of an rdbtable by multiple users. That is, if two or more users, on the same computer or perhaps on different computers on a network, attempted to modify a given rdbtable with either 'etbl' or 'dataent' at the same time the rdbtable could become corrupted. To prevent this, write concurrency control is provided by the use of a lockfile, and is in effect when either of the two utility operators is used.

The name of the lockfile is the name of the rdbtable being modified with a suffix of ".LCK". For example an rdbtable named "main.rdb" would have a lockfile named "main.rdb.LCK". The lockfile is placed in the same directory as the rdbtable and is normally removed after the modification process is complete, even if the operation is aborted with an INTERRUPT signal (CONTROL-C or <DEL>). However in the event of an emergency such as a computer system crash the lockfile could be left in place, preventing the use of 'etbl' or 'dataent' when the computer system is again operable. When an attempt to use either utility operator is made an there is and existing lockfile associated with the referenced rdbtable an online message is produced and the operator dies. In this case simply remove the lockfile with the UNIX command 'rm' and proceed. If an emergency has not occurred appropriate caution should be exercised before removing a lockfile, due to the possibility of data corruption.

## Fast Access Methods
The RDB operator 'search' may be used to execute one of two fast access methods (binary or hashtable search, although currently only binary search is implemented).

These methods are useful when the key field values of a number of rows in an existing, large rdbtable is known in advance, a common situation.

One example of updating an rdbtable using these methods is as follows. First, 'search' is used to quickly obtain a new, small rdbtable consisting of the desired rows from the existing, large rdbtable. Then 'etbl' is used to update the data in the new rdbtable, including generating new rows, changing some rows, and marking certain rows for deletion, if desired. The next stage would be to use 'mergetbl' to combine the new and old rdbtables into a new, large rdbtable, which will still be in sort order (both the old rdbtable and the new, small one will still exist for backup and/or journaling purposes). Note that the last step could be done in the background.

## Limits, A Few Minor Ones
The following limits apply.
There must not be any ASCII TAB characters in the data. This is the primary limit as the ASCII TAB character is the delimiter in rdbtables.
There must not be any pipe characters `|` used or entered as data when using the operator 'etbl'.
All of the Compare operators and Logical constructors are reserved and should not be used as column names (they are all lower case and four characters or less). They are: 'gt', 'ge', 'lt', 'le', 'eq', 'ne', 'or', 'and', 'null', 'mat', and 'nmat'.

## References
"Unix Review" magazine, March, 1991, page 24, "A 4GL Language".
"UNIX Relational Database Management", R. Manis, E. Schaffer, R. Jorgensen, 1988, Prentice Hall.
"Programming PERL", L. Wall, R. Schwartz, 1991, O'Reilly & Associates.

## Examples of Perl Expressions and Statements
Following are some examples of PERL expressions and statements of the type that might be used with RDB operators, and their meaning. Note that the operator 'row' takes a PERL expression while the operator 'compute' takes a complete PERL statement. Expressions:

    COLA mat /XXX/
                    -- column COLA contains the pattern 'XXX'.

    COLA nmat /XXX/
                    -- column COLA does NOT contain the pattern 'XXX'.

    COLA mat /^XXX/
                    -- column COLA starts with the pattern 'XXX'.

    COLA mat /XXX$/
                    -- column COLA ends with the pattern 'XXX'.

    COLA ne null
                    -- column COLA is not null (but it could contain blanks).

    COLA mat /^\s*$/
                    -- column COLA is null or contains only blank space.

    COLA eq 'YYY'
                    -- column COLA equals the literal 'YYY'.

    COLA mat /X..Y/
                    -- column COLA contains the pattern 'X..Y', which means
                    'X', followed by any two characters, then 'Y'.

    COLA mat /X.*Y/
                    -- column COLA contains the pattern 'X.*Y', which means
                    'X', followed by any number of (including zero)
                    characters, then 'Y'.

    NUMC eq 12
                    -- column NUMC equals 12.

    COLA ne null && COLB ne null
                    -- column COLA and column COLB are not null (empty).

    COLA eq 'ABC' || COLA eq 'BCD'
                    -- column COLA equals the literal 'ABC' or column COLB
                    equals the literal 'BCD'
Statements:
    COLA = COLB ;
                    -- set the value of column COLA to that of COLB.

    NUMC = NUMC - 7 ;
                    -- decrement the value of column NUMC by 7.

    NUMC -= 7 ;
                    -- (same as above).

    NUMC = NUMC / 4 ;
                    -- divide the value of column NUMC by 4.

    NUMC *= 2.3 ;
                    -- multiply the value of column NUMC by 2.3.

    $abc++ ;
                    -- increment the value of variable $abc by 1.

    ++$abc ;
                    -- (same as above).

    COLA = 'WORDS' ;
                    -- set the value of column COLA to the literal 'WORDS'.

    NUMC = 12 ;
                    -- set the value of column NUMC to 12.

    if( COLA mat /XXX/ ){ COLA .= 'YYY' ; }
                    -- If column COLA contains the pattern 'XXX' then add
                    the literal 'YYY' to the end.

    COLA .= 'YYY' if COLA =~ /XXX/ ;
                    -- (same as above).

    if( COLA eq 'ABC' || COLA eq 'BCD' ){ COLA = 'XXX' ; }
                    -- If column COLA equals 'ABC' or 'BCD' set the value
                    of COLA to 'XXX'.
