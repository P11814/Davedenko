using System;
/*
 *	Разработать приложение, в котором бы сравнивалось население трех столиц из разных стран. 
 *  Причем страна бы обозначалась пространством имен, а город – классом в данном пространстве.
 */
namespace NeverLand {
    static class PiratesIsland {
        public static int peoples = 15;
    }
}// end namespace NeverLand

namespace MosFilm {
    static class Tilimilitryamdiya {
        public static int peoples = 2;
    }
}// end namespace MosFilm

namespace SomeWhere {
    static class DesertIsland {
        public static int peoples = 1;
    }
} // end namespace SomeWhere


namespace LABA_5_5 {

    class Program {


        static void Main ( string [] args ) {

            int max=0;
            int count=0;
            string [] cities= { "PiratesIsland", "Tilimilitryamdiya", "DesertIsland" };

            if (max<NeverLand.PiratesIsland.peoples) {
                max=NeverLand.PiratesIsland.peoples;
                count=1;
            }
            if (max<MosFilm.Tilimilitryamdiya.peoples) {
                max=MosFilm.Tilimilitryamdiya.peoples;
                count=2;
            }
            if (max<SomeWhere.DesertIsland.peoples) {
                max=SomeWhere.DesertIsland.peoples;
                count=3;
            }

            for (int i=0; i<cities.Length; i++) {
                if (i==count-1) {
                    Console.WriteLine ("Max ({0}) peoples in {1}", max, cities [i]);
                }
            }



        } 
    }
}
