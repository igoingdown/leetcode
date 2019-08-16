using System;
namespace SingletonTest
{
    /// <summary>
    /// Singleton2: 线程安全的Singleton的实现，效率不高,锁加的太多.
    /// </summary>
    public sealed class Singleton2
    {
        private Singleton2()
        {
        }

        private static readonly Object o = new object();
        private static Singleton2 instance = null;
        public static Singleton2 Instance {
            get {
                lock (o)
                {
                    if (instance == null) instance = new Singleton2();
                }
                return instance;
            }

        }

    }
}
