using System.Runtime.InteropServices;
using System.Text;

namespace Wgate
{

    internal class Program
    {
        // wasi sdk does not have pthread_cond_timedwait, and its not implemented in wasi.c here.

        [StructLayout(LayoutKind.Sequential)]
        struct timespec
        {
            internal long sec;
            internal int nanosec;
        }

        static timespec ts;

        [DllImport("*")]
        static extern unsafe int nanosleep(timespec* req, void *rem);

        static FileStream fs;

        static unsafe int Main(string[] args)
        {
            // byte[] buf = new byte[8];
            int period = 1000;
            int step = -100;
            fs = new FileStream("/sys/class/gpio/gpio14/value", FileMode.OpenOrCreate, FileAccess.Write, FileShare.None,
                4096, (FileOptions) 0x20000000);
            while (true)
            {
                ts.nanosec = period * 1000000;
                TurnOn(period);
                fixed (timespec* tsptr = &ts)
                {
                    nanosleep(tsptr, null);
                    TurnOff();
                    nanosleep(tsptr, null);
                }

                period += step;
                if (period <= 100)
                {
                    step = -step;
                }
                else if (period >= 1000)
                {
                    step = -step;
                }
            }

            // //echo "out" > /sys/class/gpio/gpio9/direction
            // using (var fs = new FileStream("/sys/class/gpio/gpio14/value", FileMode.OpenOrCreate, FileAccess.Write, FileShare.None, 4096, (FileOptions)0x20000000))
            // {
            //     fs.Write(Encoding.ASCII.GetBytes("out\n"));
            // }
            return 0;
        }

        static void TurnOn(int ms)
        {
            Console.WriteLine("on " + ms);
            // //echo "1" > /sys/class/gpio/gpio9/value
            fs.Write(Encoding.ASCII.GetBytes("1"));
            fs.Flush();
        }
        static void TurnOff()
        {
            Console.WriteLine("off");
            fs.Write(Encoding.ASCII.GetBytes("0"));
            fs.Flush();
        }
    }
}