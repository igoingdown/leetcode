using System;
namespace SingletonTest
{
    /// <summary>
    /// Singleton4: 利用静态构造函数实现Singleton
    ///             .Net虚拟机第一次发现用到一个类时，自动调用该类的静态构造函数，而且只会调用一次
    ///             问题是可能过早创建该对象，如果为Singleton类添加了一个static方法，并在需要生成Singleton的实例(调用Instance创建)之前就调用该方法，
    ///             .Net虚拟机会调用static构造函数，初始化static成员的初始化。
    /// </summary>
    public sealed class Singleton4
    {
        private Singleton4()
        {
        }

        private static readonly Singleton4 instance = new Singleton4();
        public static Singleton4 Instance {
            get {
                return instance;
            }
        }
    }
}
