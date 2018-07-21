using System;

namespace SingletonTest
{
    /// <summary>
    /// Singleton1: Singleton的单线程实现，非线程安全
    /// </summary>
    public sealed class Singleton1
    {
        private Singleton1()
        {
        }

        private static Singleton1 instance = null;

        public static Singleton1 Instance {
            get {
                if (instance == null) instance = new Singleton1();
                return instance;
            }
        }
    }
}
