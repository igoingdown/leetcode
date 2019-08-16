using System;
namespace SingletonTest
{
    /// <summary>
    /// Singleton3: 比Singleton2更高效的实现，因为加锁只有一次，只有第一次生成单个Singleton对象的时候加一次锁，后面读取instance不需要加锁
    /// </summary>
    public sealed class Singleton3
    {
        private Singleton3()
        {
        }

        private static readonly Object o = new Object();
        private static Singleton3 instance = null;
        public static Singleton3 Instance {
            get {
                if (instance == null) {
                    lock(o) {
                        instance = new Singleton3();
                    }
                }
                return instance;
            }
        }
    }
}
