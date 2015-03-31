using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 3. Реализовать программу “Строительство дома”.
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
