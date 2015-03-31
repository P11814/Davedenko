using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 3. Реализовать программу “Строительство дома”.
 * Реализовать классы House, Basement, Walls, Door, Window, Roof, Worker, TeamLeader, Team и интерфейсы IWorker, IPart. 
 * Все части дома должны реализовать интерфейс IPart, для рабочих и бригадира предоставляется базовый интерфейс IWorker. 
 * Бригада строителей (Team) строит дом (using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/* Задание 3.
 * Реализовать программу “Строительство дома”.
 * Реализовать классы House, Basement, Walls, Door, Window, Roof, Worker, TeamLeader, Team и интерфейсы IWorker, IPart. 
 * Все части дома должны реализовать интерфейс IPart, для рабочих и бригадира предоставляется базовый интерфейс IWorker. 
 * Бригада строителей (Team) строит дом (House). Дом состоит из фундамента (Basement), стен (Wall), окон (Window), дверей (Door), 
 * крыши (Part). Согласно проекту, в доме должно быть 1 фундамент, 4 стены, 1 дверь, 4 окна и 1 крыша.
 * Бригада начинает работу, и строители последовательно “строят” дом, начиная с фундамента. Каждый строитель не знает заранее, 
 * на чём завершился предыдущий этап строительства, поэтому он “проверяет”, что уже построено и продолжает работу. 
 * Если в игру вступает бригадир (TeamLeader), он не строит, а формирует отчёт, что уже построено и какая часть работы выполнена.
 * В конечном итоге на консоль выводится сообщение, что строительство дома завершено и отображается “рисунок дома” (циклами).
 */
namespace Laba_8 {
    public interface IWorker {
        void buildBasement ();
        void buildWalls ();
        void buildRoof ();
    }



    public interface IPart {
        /*
        void drawBasement ();
        void drawWalls ();
        void drawRoof ();
        */
    }







    // House ______________________________________________________
    class House {

    }




    class Basement:IPart {
        int baseNum=1;
        public int BASENUM {
            get { return baseNum; }
        }
    }
    class Walls:IPart {
        int wallsNum=4;
        public int WALLSNUM {
            get { return wallsNum; }
        }
    }
    class Door:IPart {
        int doorNum=1;
        public int DOORNUM {
            get { return doorNum; }
        }
    }
    class Window:IPart {
        int winNum=1;
        public int WINNUM {
            get { return winNum; }
        }
    }
    class Roof:IPart {
        int roofNum=1;
        public int ROOFNUM {
            get { return roofNum; }
        }
    }










    // Team_____________________________________________
    public class Team {
        public static int testBasement=1;
        public static int testWalls=0;
        public static int testRoof=0;
        public static int end=0;
        public static int height=40;
        public static int width=60;
        public static char[,] house=new char[100, 100];

    }






    public class Workers:Team, IWorker {
        string workerName;

        public Workers (string name) {
            this.workerName=name;
        }




        public void buildBasement () {
            int count;
            if (testBasement>0&&testBasement<5) {

                ++testBasement;
                ++testWalls;
                Console.WriteLine ("{0} строит подвал", workerName);

                for (int i=38; i<40; i++) {
                    for (int j=0; j<35; j++) {
                        house[i, j]='*';
                    }
                }

                for (int i=30; i<32; i++) {
                    for (int j=8; j<43; j++) {
                        house[i, j]='*';
                    }
                }

                count=0;
                for (int i=30; i<38; i++) {
                    count++;
                    house[i, 9-count]='*';
                    house[i, 10-count]='*';
                    house[i, 43-count]='*';
                    house[i, 44-count]='*';
                }
                house[38, 35]='*';
            }
            else {
                Console.WriteLine ("{0}: - Зовите прораба!", workerName);
            }

        }

        public void buildWalls () {
            int count;
            if (testWalls>3&&testWalls<20) {

                ++testWalls;
                ++testRoof;
                Console.WriteLine ("{0} строит стену ", workerName);

                if (testWalls>3&&testWalls<7) {  //1               
                    for (int i=27; i<37; i++) {
                        house[i, 10]='|';
                    }
                    for (int i=24; i<34; i++) {
                        house[i, 14]='|';
                    }
                    count=0;
                    for (int j=11; j<14; j++) {
                        count++;
                        house[27-count, j]='/';
                        house[37-count, j]='/';
                    }
                    for (int i=30; i<32; i++) {
                        for (int j=11; j<14; j++) {
                            house[i, j]=' ';
                        }
                    }
                }

                if (testWalls>8&&testWalls<11) {  // 2

                    for (int i=15; i<34; i++) {

                        house[23, i]='_';
                        house[33, i]='-';
                    }
                    for (int i=24; i<34; i++) {
                        house[i, 34]='|';
                    }
                    for (int i=30; i<32; i++) {
                        for (int j=15; j<34; j++) {
                            house[i, j]=' ';
                        }
                    }
                }


                if (testWalls>12&&testWalls<14) {  //3               
                    for (int i=27; i<37; i++) {
                        house[i, 30]='|';
                    }
                    for (int i=24; i<34; i++) {
                        house[i, 34]='|';
                    }
                    count=0;
                    for (int j=31; j<34; j++) {
                        count++;
                        house[27-count, j]='/';
                        house[37-count, j]='/';
                    }
                    for (int i=31; i<34; i++) {

                        house[33, i]=' ';
                    }

                }



                if (testWalls>16&&testWalls<20) {  // 4

                    house[35, 12]=' '; house[34, 13]=' '; house[36, 11]='_';

                    for (int i=12; i<30; i++) {
                        house[26, i]='_';
                        house[36, i]='_';
                    }


                    for (int j=15; j<30; j++) {
                        house[33, j]=' ';
                    }
                    for (int i=27; i<34; i++) {
                        house[i, 14]=' ';
                    }
                   
                }




            }
            else {
                Console.WriteLine ("{0}: - Зовите прораба!", workerName);
            }

        }

        public void buildRoof () {
            if (testRoof>15&&testRoof<20) {
                ++testRoof;
                ++end;
                Console.WriteLine ("{0} строит крышу", workerName);

            }
            else {
                Console.WriteLine ("{0}: - Зовите прораба!", workerName);
            }
        }

    }






    public class TeamLeader:Team, IWorker {
        string workerName;

        public TeamLeader (string name) {
            this.workerName=name;
        }
        public void showHouse () {
            for (int i=0; i<height; i++) {
                for (int j=0; j<width; j++) {
                    Console.Write (house[i, j]);
                }
                Console.WriteLine ();
            }
        }
        public void buildBasement () {
            if (testBasement==5) {
                Console.WriteLine ("{0} проверил. Подвал построен!\n", workerName);
            }
            else {
                Console.WriteLine ("{0} проверил. Подвал не построен!\n", workerName);
            }

        }

        public void buildWalls () {
            if (testWalls==20) {
                Console.WriteLine ("{0} проверил. Все стены построены!\n", workerName);
            }
            else {
                Console.WriteLine ("{0} проверил. Не все стены построены!\n", workerName);
            }

        }

        public void buildRoof () {
            if (testRoof==16) {
                Console.WriteLine ("{0} проверил. Крыша построена!\n", workerName);
            }
            else {
                Console.WriteLine ("{0} проверил. Крыша не построена!\n", workerName);
            }

        }
    }









    class Program {



        static void Main (string[] args) {
            List<IWorker> workers=new List<IWorker> ();
            workers.Add (new Workers ("Катя"));
            workers.Add (new Workers ("Петя"));
            workers.Add (new Workers ("Женя"));
            workers.Add (new Workers ("Лена"));
            TeamLeader prorab=new TeamLeader ("Вася");

            int x=0;
            while (true) {

                try {
                    x=int.Parse (Console.ReadLine ());
                }
                catch (FormatException) {
                    Console.WriteLine ("Введите число!");
                }



                switch (x) {
                    case 1:
                        foreach (IWorker w in workers) {
                            w.buildBasement ();
                        }
                        break;
                    case 2:
                        foreach (IWorker w in workers) {
                            w.buildWalls ();
                        }
                        break;
                    case 3:
                        foreach (IWorker w in workers) {
                            w.buildRoof ();
                        }
                        break;
                    case 4:
                        prorab.buildBasement ();
                        prorab.buildWalls ();
                        prorab.buildRoof ();
                        break;
                    case 5:
                        prorab.showHouse ();
                        break;
                }
            }



        }
    }
}
House). Дом состоит из фундамента (Basement), стен (Wall), окон (Window), дверей (Door), 
 * крыши (Part). Согласно проекту, в доме должно быть 1 фундамент, 4 стены, 1 дверь, 4 окна и 1 крыша.
 * Бригада начинает работу, и строители последовательно “строят” дом, начиная с фундамента. Каждый строитель не знает заранее, 
 * на чём завершился предыдущий этап строительства, поэтому он “проверяет”, что уже построено и продолжает работу. 
 * Если в игру вступает бригадир (TeamLeader), он не строит, а формирует отчёт, что уже построено и какая часть работы выполнена.
 * В конечном итоге на консоль выводится сообщение, что строительство дома завершено и отображается “рисунок дома” (циклами).
 */
namespace Laba_8 {
    public interface IWorker {
        void buildBasement();
        void buildWalls();
        void buildRoof();
    }
    public interface IPart {

    }

    // House
    class House {

    }
    class Basement: IPart {
        int baseNum = 1;
    }
    class Walls: IPart {
        int wallsNum = 4;
    }
    class Door: IPart {
        int doorNum = 1;
    }
    class Window: IPart {
        int winNum = 1;
    }
    class Roof: IPart {
        int roofNum = 1;
    }




    // Team
    public class Team {
        int test;
        public int TEST {
            get {
                return test;
            }
            set {
                this.test = value;
            }
        }
    }


    public class Workers: IWorker {
        public void buildBasement() {

            Team t = new Team ( );
            if (t.TEST == 0) {
                Console.WriteLine ("Строим подвал");
            }

            t.TEST++;
        }

        public void buildWalls() {
            //Console.WriteLine ("Строим подвал");
        }

        public void buildRoof() {
            //Console.WriteLine ("Строим подвал");
        }

    }

    class TeamLeader: IWorker {
        public void buildBasement() {
            Team t = new Team ( );
            if (t.TEST == 1) {
                Console.WriteLine ("Подвал построен");
            }
            else {
                Console.WriteLine ("Подвал непостроен");
            }

        }

        public void buildWalls() {
            Team t = new Team ( );
            if (t.TEST > 1) {
                Console.WriteLine ("Стена  построена");
            }
            else {
                Console.WriteLine ("Стена  непостроена");
            }
        }

        public void buildRoof() {
            //Console.WriteLine ("Строим подвал");
        }
    }

    class Program {



        static void Main(string [] args) {
            Workers workers = new Workers ( );
            TeamLeader brigadir = new TeamLeader ( );

            bool ok = true;
            while (ok) {
                Console.WriteLine (@"Что будем строить ?
-----------
1 Подвал
2 Стены
3 Крышу
4 Проверка");
                int x = int.Parse (Console.ReadLine ( ));
                switch (x) {
                    case 1:
                        workers.buildBasement ( );
                        break;
                    case 2:
                        workers.buildWalls ( );
                        break;
                    case 3:
                        workers.buildRoof ( );
                        break;
                    case 4:
                        brigadir.buildBasement ( );
                        brigadir.buildWalls ( );
                        brigadir.buildRoof ( );
                        break;
                }


            }


        }
    }
}
