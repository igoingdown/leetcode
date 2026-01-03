using System;
namespace SingletonTest
{
    /// <summary>
    /// Singleton5的优势是相对于Singleton4而言的
    /// 即使为Singleton5添加了static方法并在调用Instance之前调用改方法，也不会对Instance进行初始化。
    /// 只有调用Instance的时候才会进行初始化！
    /// </summary>
    public sealed class Singleton5
    {
        private Singleton5()
        {
        }

        public static Singleton5 Instance {
            get{
                return Nested.instance;
            }
        }

        private class Nested {
            static Nested() {
                
            }

            internal static readonly Singleton5 instance = new Singleton5();
        }
    }
}
