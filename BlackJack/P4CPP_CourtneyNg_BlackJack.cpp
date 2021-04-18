/*
Courtney Ng
Period 4
*/

//libraries
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

//var
/***********************************************************************/
string ranks[13] = {"Ace", "Two", "Three", 
					"Four", "Five", "Six", 
					"Seven", "Eight", "Nine", 
					"Ten", "Jack", "Queen", "King"};
					
string suits[4] = {"Diamonds", "Clubs", "Hearts", "Spades"};

/***********************************************************************/

class card{
	private:
		int value;
		string rank;
		string suit;
		
	public:
		//setter functions
		void set_rank(string r){
			rank = r;
		}
		void set_suit(string s){
			suit = s;
		}
		void set_value(int v){
			value = v;
		}
		
		
		//getter functions
		string get_rank(){
			return rank;
		}
		string get_suit(){
			return suit;
		}
		int get_value(){
			return value;
		}
		
		//display|print
		void display(){
			cout << "value: [" << value << "]" << " - " << rank << " of " << suit << endl;
		}
};

void shuffle(vector <card> &d);
card dealfrom(vector <card> &d);

/********************************************************main********************************************************/
int main(){
	/*******************************/
	srand(time(0));
	vector <card> deck(52);
	vector <card> hand(0);
	vector <card> dealer(0);
	card temp;
	bool playagain = true;
	char again;
	/*******************************/
	
	do{
		for(int i=0; i<52; i++){
			if(i%13 == 0){
				//ace, also needs 1 val condition
				deck[i].set_value(11);
			}
			
			else if(i%13 >= 9){
				deck[i].set_value(10);
			}
			
			else{
				deck[i].set_value(i%13 + 1);
			}
			
			deck[i].set_rank(ranks[i%13]);
			deck[i].set_suit(suits[i/13]);
		}
		
		
	}while(playagain == true);
	
}
/********************************************************main********************************************************/

void shuffle(vector <card> &d){
	card temp;
	for(int i=0; i<52; i++){
		int r = rand()%52;
		temp = d[i];
		d[i] = d[r];
		d[r] = temp;
	}
}

card deadlfrom(vector <card> &d){
	card c;
	c = d[d.size() - 1];
	d.pop_back(); //pop card out of deck disappears
	return c;
}












