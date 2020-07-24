# interpreter_web_browsers
-Interpreter for work with web
-Interpreter for work with web pages on Chrome and Edge.
-Realized on C++ and C#. Part on C++ is lexer and parser. Work with browsers realized due to Selenium library.
-Supports arithmetic operations, variables(types: integer, string, boolean, handle for window of browsTherer).
-There is also peep-hole optimizition for arithmetic operations.
-Interpreter supports work with differents windows at one time, clicking, inputing, scrolling. Elements are searched by html id or name.
-The main thing - there is communication between two processes one on the C# and another one on the C++. They interacts using shared memory, where is a two bytes to get each other know, if another process can read from other.
-Running every new browser window calls new process.

-Watch for lexemes in file Syntax.pdf
-Example of using
------------------------------------------------------------------------------------------------------------------------------------------------------------
ref := 'instagram.com'                      # creating string var to contain a website addres in this case
handle := run chrome                        # creating a handle of Chrome window using command 'run', after which goes'chrome' or 'edge'
handle open ref                             # command 'open' after handle of browser opens in the window refference
login := 'oleh_sakharchuk_'                 # creating string variable
handle click name 'username'                # in opened window at opened site search for elemenst with HTML parameter 'name' and click it
handle input name 'username' login          # in opened window at opened site search for elemenst with HTML parameter 'name' and name 'username' and input there the text, that goes after name if tag - 'login'
handle input name 'password' 'arkadiy18'    # in opened window at opened site search for elemenst with HTML parameter 'name' and name 'password' and input there the text, that goes after name if tag - 'login'
handle quit                                 # closes window of browser with handle 'handle', also kills process that runs browser

------------------------------------------------------------------------------------------------------------------------------------------------------------
-example of optimized code
-optimizing useful only for session with many arithmetic expressions
-to turn on optimization we should write '#optimize' in first row of code
-code starts from next line
#optimize
x := 40 * 24 + 24 * 46 # interpreter knows that  in this operation are the same multiplicators and makes from this expression next one: 24*(40+46)


-For more examples write me sugaryoleh@gmail.com


!!!IMPORTANT!!!
Be sure that you have the latest version of Selenium!
