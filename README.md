# interpreter_web_browsers
-Interpreter for work with web pages on Chrome and Edge.
-Wriiten on C++ and C#. Part on C++ is lexer and parser. C# with Selenium gives an opportunity to manipulate web pages.
-Supports arithmetic operations, variables(types: integer, string, boolean, handler for window of browser).
-Peep-hole optimized
-Interpreter supports work with differents windows at one time, clicking, inputing, scrolling. Elements are searched by html id or name.
-The main thing - there is communication between two processes one on the C# and another one on the C++. They interacts using shared memory, where is a two bytes to get each other know, if another process can read from other.
-Running every new browser window calls new process.

-Watch for lexemes in file Syntax.pdf
-Scenario of using(an authorization to the website)
------------------------------------------------------------------------------------------------------------------------------------------------------------
<var name> := '<url>'                                 # creating string variable to store a website utl addres
<handler> := run chrome                               # keyword run creates handler of chosen browser
<handler> open <var name>                             # handler opens url
<login> := '<username>'                               # creating and initalizing variable <login> which will be used for storing username
<handler> click name '<username_field>'               # handler calls raises 'click' event at object with name <username_field> 
<handler> input name '<username_field>' <login>       # handler inputs login to '<usernmae_field>' 
<handler> click name '<password_field>'               # handler calls raises 'click' event at object with name <password_field> 
<handler> input name '<password_field>' '<password>'  # handler inputs password to 'password_field>' 
handle quit                                           # closes window of browser with handler 'handler', also kills process that runs browser

------------------------------------------------------------------------------------------------------------------------------------------------------------
-Scenario of with peep-hole optimized code
-optimizing is useful only if session deals with arithmetic expressions
-to turn on optimization we should write '#optimize' in first row of code
-code starts from next line
#optimize
x := 40 * 24 + 24 * 46 # interpreter finds the same multiplicators(24) and a really calculated expression looks like 'x := 24*(40+46)'

-For more examples email me at sugaryoleh@gmail.com


!!!IMPORTANT!!!
Be sure that you have the latest version of Selenium!
