using System;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium.Edge;
using OpenQA.Selenium.Support.UI;

namespace browser_manager
{
    public class PageManager
    {
        private static IWebDriver driver = null;
        private static DefaultWait<IWebDriver> fluentWait;
        public static IWebDriver getInstance()
        {
            if (driver == null)
            {
                start("chrome");
            }
            return driver;
        }
        private static void initFluentWaiter()
        {
            fluentWait = new DefaultWait<IWebDriver>(getInstance());
            fluentWait.Timeout = TimeSpan.FromSeconds(5);
            fluentWait.PollingInterval = TimeSpan.FromMilliseconds(250);
            /* Ignore the exception - NoSuchElementException that indicates that the element is not present */
            fluentWait.IgnoreExceptionTypes(typeof(NoSuchElementException));
            fluentWait.Message = "Element to be searched not found";
        }
        public static int start(string br)
        {
            if (driver == null)
            {
                //driver = new ChromeDriver();
                try
                {
                    if (br == "chrome")
                    {
                        driver = new ChromeDriver();
                        driver.Url = "https://google.com";

                        initFluentWaiter();
                        return 1;
                    }
                    else if (br == "edge")
                    {
                        driver = new EdgeDriver();
                        driver.Url = "https://google.com";
                        initFluentWaiter();
                        return 1;
                    }
                    else return 2;
                }
                catch (DriverServiceNotFoundException)
                {
                    return 2;
                }
            }
            else return 3;
            //driver.Manage().Window.Maximize();
        }
        public static int open(string url)
        {
            if (url.Length > 8)
            {
                if (url.Substring(0, 8) != "https://")
                {
                    url = "https://" + url;
                }
            }
            getInstance().Url = url;
            //driver.Url = url;
            return 1;
        }
        public static int quit()
        {
            if (driver != null)
            {
                driver.Close();
                driver.Quit();
                return 0;
            }
            else return 6;
        }
        public static int click(string key, string val)
        {
            IWebElement el = getElem(key, val);
            if (el != null)
            {
                try
                {
                    el.Click();
                    return 1;
                }
                catch (ElementNotInteractableException)
                {
                    return 4;
                }
            }
            else
                return 5;
        }
        public static int input(string key, string val, string text)
        {

            IWebElement el = getElem(key, val);
            if (el != null)
            {
                try
                {
                    if (text == "/enter")
                    {
                        el.SendKeys(Keys.Enter);
                        return 1;

                    }
                    if (text == "/backspace")
                    {
                        el.SendKeys(Keys.Backspace);
                        return 1;
                    }
                    else el.SendKeys(text);
                    return 1;
                }
                catch (ElementNotInteractableException)
                {
                    Console.WriteLine("elemnt is not inputable");
                    return 4;
                }
            }
            else
                return 5;
        }
        public static int clear(string key, string val)
        {
            IWebElement el = getElem(key, val);
            if (el != null)
            {
                try
                {
                    el.Clear();
                    return 1;
                }
                catch (InvalidElementStateException)
                {
                    return 6;
                }
            }
            else
                return 5;
        }
        public static IWebElement getElem(string key, string val)
        {
            if (key == "name")
            {
                try
                {
                    return fluentWait.Until(x => x.FindElement((By.Name(val))));
                    //return getInstance().FindElement(By.Name(val));
                }
                
                catch (NoSuchElementException ex)
                {
                    Console.WriteLine("no such element");
                    return null;
                }
                
            }
            else if (key == "id")
            {
                try
                {
                    //return getInstance().FindElement(By.Id(val));
                    return fluentWait.Until(x => x.FindElement((By.Id(val))));
                }
                catch (NoSuchElementException)
                {
                    Console.WriteLine("no such element");
                    return null;
                }
                catch (WebDriverTimeoutException ex)
                {
                    Console.WriteLine("no such element");
                    return null;
                }

            }
            else if (key == "class")
            {
                try
                {
                    //return getInstance().FindElement(By.Id(val));
                    return fluentWait.Until(x => x.FindElements((By.ClassName(val))))[0];
                }
                catch (NoSuchElementException)
                {
                    return null;
                }
                catch (WebDriverTimeoutException ex)
                {
                    Console.WriteLine("no such element");
                    return null;
                }
            }
            else return null;
        }
    }
}