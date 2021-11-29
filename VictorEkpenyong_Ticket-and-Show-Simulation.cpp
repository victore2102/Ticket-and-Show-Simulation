// Victor Ekpenyong
// October 2020

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

//global variables
char choice;
char d_request, s_request;
int n_request;
char seats[3][3][20];
int d,r,c;

//Function declarations
char get_menu_choice(char choice);
void print_chart();
void sell_seat(char &d_request, char &s_request, int &n_request);
void print_day_list();
void print_section_list();
void cashier();



int main()
{
       //Initialization of seating chart. All seats empty
       for (d=0; d<3; d++)
       {
           for (r=0; r<3; r++)
           {
               for (c=0; c<20; c++)
               {
                   seats[d][r][c]= '-';
               }
           }
       }
        //Outputted at the beginning of program. All seats empty
        cout << "Start to initialize seating chart." << endl << "All seats have been initialized." << endl << endl;


        //returns choice value user inputs
        char opp = get_menu_choice(choice);

        //Loop of menu running with conditional statements of what function to run based on users choice input
        do
        {
            switch (opp)
                {

                    case 'S': sell_seat(d_request, s_request, n_request);
                    break;
                    case 'C': print_chart();
                    break;
                    case 'D': print_day_list();
                    break;
                    case 'F': print_section_list();
                    break;
                    case 'Q': cout << "Goodbye" << endl;
                                return 0; //Program terminates gracefully
                    break;
                    default: cout << "\"" << opp << "\"" << " is not a valid choice. Try again." << endl << endl; //Error handling if invalid choice is given
                }
        }while (opp = get_menu_choice(choice));

    //Graceful exit
    return 0;
}




//presents menu, gets user selection, returns only valid selection
char get_menu_choice(char choice)
    {

                    cout << "      *** Main Menu ***" << endl;
                    cout << "S - Sell a Ticket" << endl;
                    cout << "C - Display Seating Chart" << endl;
                    cout << "D - Display Sales Summary - Day Listing" << endl;
                    cout << "F - Display Sales Summary - Floor Listing" << endl;
                    cout << "Q - Quit" << endl << endl;
                    cout << "Your choice: ";
                    cin >> choice;
                    cout << endl;

                    choice = toupper(choice);

                    //choice input being returned
                    return choice;



    }


//checks if a seat selection is available, updates data as sold
void sell_seat(char &d_request, char &s_request, int &n_request)
    {
        //Loop which runs while day, section, or seat input is invalid
        do
        {

               cout << "Enter seat request by Day (T)hursday, (F)riday, (S)aturday" << endl
                << "followed by Section (F)loor, (B)alcony, (U)pper Balcony" << endl
                << "followed by seat number (1 - 20 )." << endl << endl;

            cout << "Seat:  ";
            cin >> d_request >> s_request >> n_request;
            cout << endl;

            //converts all values inputted to uppercase values
            d_request = toupper(d_request);
            s_request = toupper(s_request);



            //Conditional statements if input for day, section, or seat are invalid
            if((d_request != 'T' && d_request != 'F' && d_request != 'S') && (s_request != 'F' && s_request != 'B' && s_request != 'U') && (n_request < 1 || n_request > 20))
            {
                cout << "Your day, section, and seat inputs are invalid. Please try again." << endl << endl;
            }
            else if((d_request != 'T' && d_request != 'F' && d_request != 'S') && (s_request != 'F' && s_request != 'B' && s_request != 'U'))
            {
                cout << "Your day and section inputs are invalid. Please try again." << endl << endl;
            }
            else if((d_request != 'T' && d_request != 'F' && d_request != 'S') && (n_request < 1 || n_request > 20))
            {
                cout << "Your day and seat inputs are invalid. Please try again." << endl << endl;
            }
            else if((s_request != 'F' && s_request != 'B' && s_request != 'U') && (n_request < 1 || n_request > 20))
            {
                cout << "Your section and seat inputs are invalid. Please try again." << endl << endl;
            }
            else if(d_request != 'T' && d_request != 'F' && d_request != 'S')
            {
                cout << "Your day input is invalid. Please try again." << endl << endl;
            }
            else if (s_request != 'F' && s_request != 'B' && s_request != 'U')
            {
                cout << "Your section input is invalid. Please try again." << endl << endl;
            }
            else if (n_request < 1 || n_request > 20)
            {
                cout << "Your seat input is invalid. Please try again." << endl << endl;
            }

        }while((d_request != 'T' && d_request != 'F' && d_request != 'S') || (s_request != 'F' && s_request != 'B' && s_request != 'U') || (n_request < 1 || n_request > 20));

        switch( d_request )
        {
        case 'T': d = 0;
        break;
        case 'F': d = 1;
        break;
        case 'S': d = 2;
        break;
        }

        switch( s_request )
        {
        case 'F': r = 0;
        break;
        case 'B': r = 1;
        break;
        case 'U': r = 2;
        break;
        }

        //outputs whether seat is available or not and updates chart
        cashier();

    }


//main ticket selling procedure – gets/validates seat selection
void cashier()
    {

        if(seats[d][r][n_request - 1] == '-')
        {
            cout << "Congratulations! You got the seat." << endl << endl;
            seats[d][r][n_request - 1] = '*';
        }
        else if(seats[d][r][n_request - 1] == '*')
        {
            cout << "That seat was taken, please select another." << endl << endl;
        }

    }


//displays seating chart
void print_chart()
    {


       string position, day;

       for (d=0; d<3; d++)
       {
           switch (d)
           {
               case 0: day = "Thursday";
               break;
               case 1: day = "Friday";
               break;
               case 2: day = "Saturday";
           }
           cout << day << endl;


            for (r=0; r<3; r++)
            {
                    switch(r)
                    {
                       case 0: position = "Floor";
                       break;
                       case 1: position = "Balcony";
                       break;
                       case 2: position = "Upper Balcony";
                    }
                    cout << setw(8) << " " << setw(13) << left << position << ": ";
                for (c=0; c<20; c++)
                {
                    cout << seats[d][r][c] << " ";

                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;


    }



//displays sales summary, ordered by days
void print_day_list()
    {
        //variables used and initialized at beginning
        int T_f_t = 0;
        int F_f_t = 0;
        int S_f_t = 0;
        int T_b_t = 0;
        int F_b_t = 0;
        int S_b_t = 0;
        int T_u_t = 0;
        int F_u_t = 0;
        int S_u_t = 0;

        //Loop which updates values of appropriate variable
        for (d=0; d<3; d++)
        {
            for (r=0; r<3; r++)
            {
                for (c=0; c<20; c++)
                {
                    if (seats[d][r][c]== '*')
                    {
                        switch (d)
                        {
                            case 0: switch(r)
                                    {
                                    case 0: T_f_t++;
                                    break;
                                    case 1: T_b_t++;
                                    break;
                                    case 2: T_u_t++;
                                    }
                            break;
                            case 1: switch(r)
                                    {
                                    case 0: F_f_t++;
                                    break;
                                    case 1: F_b_t++;
                                    break;
                                    case 2: F_u_t++;
                                    }
                            break;
                            case 2: switch(r)
                                    {
                                    case 0: S_f_t++;
                                    break;
                                    case 1: S_b_t++;
                                    break;
                                    case 2: S_u_t++;
                                    }
                        }
                    }
                }
            }
        }


               //Chart being printed
               for (d=0; d<3; d++)
               {

               switch (d)
               {
                   case 0: cout << "Thursday" << endl;
                   break;
                   case 1: cout << "Friday" << endl;
                   break;
                   case 2: cout << "Saturday" << endl;
               }
               for (r=0; r<3; r++)
               {
                   switch (d)
               {
                   case 0: switch(r)
                       {
                           case 0: cout << setw(8) << " " << setw(13) << left << "Floor" << ":   Tickets Sold:   " << T_f_t << "   " << "$" << 30*T_f_t << endl;
                           break;
                           case 1: cout << setw(8) << " " << setw(13) << left << "Balcony" << ":   Tickets Sold:   " << T_b_t << "   " << "$" << 20*T_b_t << endl;
                           break;
                           case 2: cout << setw(8) << " " << setw(13) << left << "Upper Balcony" << ":   Tickets Sold:   " << T_u_t << "   " << "$" << 10*T_u_t << endl;
                       }
                   break;
                   case 1: switch(r)
                       {
                           case 0: cout << setw(8) << " " << setw(13) << left << "Floor" << ":   Tickets Sold:   " << F_f_t << "   " << "$" << 30*F_f_t << endl;
                           break;
                           case 1: cout << setw(8) << " " << setw(13) << left << "Balcony" << ":   Tickets Sold:   " << F_b_t << "   " << "$" << 20*F_b_t << endl;
                           break;
                           case 2: cout << setw(8) << " " << setw(13) << left << "Upper Balcony" << ":   Tickets Sold:   " << F_u_t << "   " << "$" << 10*F_u_t << endl;
                       }
                   break;
                   case 2: switch(r)
                       {
                           case 0: cout << setw(8) << " " << setw(13) << left << "Floor" << ":   Tickets Sold:   " << S_f_t << "   " << "$" << 30*S_f_t << endl;
                           break;
                           case 1: cout << setw(8) << " " << setw(13) << left << "Balcony" << ":   Tickets Sold:   " << S_b_t << "   " << "$" << 20*S_b_t << endl;
                           break;
                           case 2: cout << setw(8) << " " << setw(13) << left << "Upper Balcony" << ":   Tickets Sold:   " << S_u_t << "   " << "$" << 10*S_u_t << endl;
                       }
               }

               }
               cout << endl;
            }

        //Total tickets and total price being calculated
        int TOTAL_t = (T_f_t + F_f_t + S_f_t + T_b_t + F_b_t + S_b_t + T_u_t + F_u_t + S_u_t);
        int TOTAL_p = (30*(T_f_t + F_f_t + S_f_t) + 20*(T_b_t + F_b_t + S_b_t) + 10*(T_u_t + F_u_t + S_u_t));
        //Total tickets and price being outputted
        cout << "Total ticket sales for all shows: " << TOTAL_t << "  $" << TOTAL_p << endl << endl;

    }


//displays sales summary, ordered by sections
void print_section_list()
    {
        //variables used and initialized at beginning
        int T_f_t = 0;
        int F_f_t = 0;
        int S_f_t = 0;
        int T_b_t = 0;
        int F_b_t = 0;
        int S_b_t = 0;
        int T_u_t = 0;
        int F_u_t = 0;
        int S_u_t = 0;

        //Loop which updates values of appropriate variable
        for (r=0; r<3; r++)
        {
            for (d=0; d<3; d++)
            {
                for (c=0; c<20; c++)
                {
                    if (seats[d][r][c]=='*')
                    {
                        switch (r)
                        {
                            case 0: switch(d)
                                    {
                                    case 0: T_f_t++;
                                    break;
                                    case 1: T_b_t++;
                                    break;
                                    case 2: T_u_t++;
                                    }
                            break;
                            case 1: switch(d)
                                    {
                                    case 0: F_f_t++;
                                    break;
                                    case 1: F_b_t++;
                                    break;
                                    case 2: F_u_t++;
                                    }
                            break;
                            case 2: switch(d)
                                    {
                                    case 0: S_f_t++;
                                    break;
                                    case 1: S_b_t++;
                                    break;
                                    case 2: S_u_t++;
                                    }
                        }
                    }
                }
            }
        }


               //Chart being printed
               for (r=0; r<3; r++)
               {

               switch (r)
               {
                   case 0: cout << "Floor" << endl;
                   break;
                   case 1: cout << "Balcony" << endl;
                   break;
                   case 2: cout << "Upper Balcony" << endl;
               }
               for (d=0; d<3; d++)
               {
                switch (r)
               {
                   case 0: switch(d)
                       {
                           case 0: cout << setw(8) << " " << setw(13) << left << "Thursday" << ":   Tickets Sold:   " << T_f_t << "   " << "$" << 30*T_f_t << endl;
                           break;
                           case 1: cout << setw(8) << " " << setw(13) << left << "Friday" << ":   Tickets Sold:   " << T_b_t << "   " << "$" << 30*T_b_t << endl;
                           break;
                           case 2: cout << setw(8) << " " << setw(13) << left << "Saturday" << ":   Tickets Sold:   " << T_u_t << "   " << "$" << 30*T_u_t << endl;
                       }
                   break;
                   case 1: switch(d)
                       {
                           case 0: cout << setw(8) << " " << setw(13) << left << "Thursday" << ":   Tickets Sold:   " << F_f_t << "   " << "$" << 20*F_f_t << endl;
                           break;
                           case 1: cout << setw(8) << " " << setw(13) << left << "Friday" << ":   Tickets Sold:   " << F_b_t << "   " << "$" << 20*F_b_t << endl;
                           break;
                           case 2: cout << setw(8) << " " << setw(13) << left << "Saturday" << ":   Tickets Sold:   " << F_u_t << "   " << "$" << 20*F_u_t << endl;
                       }
                   break;
                   case 2: switch(d)
                       {
                           case 0: cout << setw(8) << " " << setw(13) << left << "Thursday" << ":   Tickets Sold:   " << S_f_t << "   " << "$" << 10*S_f_t << endl;
                           break;
                           case 1: cout << setw(8) << " " << setw(13) << left << "Friday" << ":   Tickets Sold:   " << S_b_t << "   " << "$" << 10*S_b_t << endl;
                           break;
                           case 2: cout << setw(8) << " " << setw(13) << left << "Saturday" << ":   Tickets Sold:   " << S_u_t << "   " << "$" << 10*S_u_t << endl;
                       }
               }
               }
               cout << endl;
            }

        //Total tickets and total price being calculated
        int TOTAL_t = (T_f_t + F_f_t + S_f_t + T_b_t + F_b_t + S_b_t + T_u_t + F_u_t + S_u_t);
        int TOTAL_p = (30*(T_f_t + T_b_t + T_u_t) + 20*(F_f_t + F_b_t + F_u_t) + 10*(S_f_t + S_b_t + S_u_t));
        //Total tickets and price being outputted
        cout << "Total ticket sales for all shows: " << TOTAL_t << "  $" << TOTAL_p << endl << endl;

    }
