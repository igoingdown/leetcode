using System;

namespace SingletonTest
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var instance11 = Singleton1.Instance;
            var instance12 = Singleton1.Instance;
            if (instance11 == instance12) Console.WriteLine("y");
            Console.WriteLine("Hello World!");
        }
    }
}
