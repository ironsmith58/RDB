# RDB

> RDB: a Relational Database Management System
>
> WORKING DRAFT
> Walter V. Hobbs <hobbs@rand.org>
>
> Summary
>
> RDB is a fast, portable, relational database management system without arbitrary limits, (other than memory and processor speed) that runs under, and interacts with, the UNIX Operating system.
>
> It uses the Operator/Stream DBMS paradigm described in "Unix Review", March, 1991, page 24, entitled "A 4GL Language". There are a number of "operators" that each perform a unique function on the data. The "stream" is suplied by the UNIX Input/Output redirection mechanism. Therefore each operator processes some data and then passes it along to the next operator via the UNIX pipe function. This is very efficient as UNIX pipes are implemented in memory (at least in versions of UNIX at RAND). RDB is compliant with the "Relational Model".
>
> The data is contained in regular UNIX ACSII files, and so can be manipulated by regular UNIX utilities, e.g. ls, wc, mv, cp, cat, more, less, editors like the RAND editor 'e', head, RCS, etc.
>
> The form of each file of data is that of a relation, or table, with rows and columns of information.
>
> To extract information, a file of data is fed to one or more "operators" via the UNIX Input/Output redirection mechanism.
>
> There are also programs to generate reports, and to generate, modify, and validate the data.

_quoted from "RDB: a Relational Database Management System, Walter V. Hobbs, unknown publication date, https://compbio.soe.ucsc.edu/rdb/_
