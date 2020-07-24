using System;
using System.IO;
using System.IO.MemoryMappedFiles;
using System.Collections.Generic;

namespace browser_manager
{
    class Program
    {
        static int Processor(List<string> strs)
        {
            try
            {
                if (strs[0] == "run")
                {
                    return browser_manager.PageManager.start(strs[1]);
                }
                else if (strs[0] == "open")
                {
                    return browser_manager.PageManager.open(strs[1]);
                }
                else if (strs[0] == "quit")
                {
                    return browser_manager.PageManager.quit();
                }
                else if (strs[0] == "input")
                {
                    return browser_manager.PageManager.input(strs[1], strs[2], strs[3]);
                }
                else if (strs[0] == "click")
                {
                    return browser_manager.PageManager.click(strs[1], strs[2]);
                }
                else if (strs[0] == "clear")
                {
                    return browser_manager.PageManager.clear(strs[1], strs[2]);
                }
                else return 7;
            }
            catch (ArgumentOutOfRangeException)
            {
                return 7;
            }


        }
        static int Main(string[] argc)
        {
            MemoryMappedFile mmf;
            MemoryMappedViewAccessor accr;
            try
            {
                mmf = MemoryMappedFile.OpenExisting(argc[0]);
                accr = mmf.CreateViewAccessor();
                try
                {
                    while (true)
                    {
                        List<string> strs = new List<string>();
                        string text = "";
                        int i = 0;
                        char c = accr.ReadChar(i);
                        i = 2;
                        if (c != '0')
                        {
                            while (true)
                            {
                                i += 2;
                                c = accr.ReadChar(i);
                                if (c == '@')
                                {
                                    strs.Add(text);
                                    text = "";
                                    break;
                                }
                                else if (c == '$')
                                {
                                    strs.Add(text);
                                    text = "";
                                }
                                else
                                {
                                    text += c;
                                }
                            }
                            int val = Processor(strs);
                            Console.WriteLine(val);
                            accr.Write(0, '0');
                            accr.Write(2, (int)((char)val));
                        }
                    }
                }
                catch (OpenQA.Selenium.WebDriverTimeoutException ex)
                {
                    Console.WriteLine(ex.ToString());
                    accr.Write(0, '0');
                    accr.Write(2, (int)((char)9));
                    Console.Read();
                    return 0;
                }
                
    
            }
            catch (FileNotFoundException ex)
            {
                Console.WriteLine(ex.ToString());
                Console.Read();
                return 0;
            }
        }
    }
}
