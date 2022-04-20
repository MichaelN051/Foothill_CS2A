//code for April 19, 2022 class
// We're gonna try and print the position of a bullet
//shot horizontally from an edge of a cliff
// Edited by Michael Nguyen

#include <iostream>

using namespace std;

//we plot the position of the bullet every 0.01 of a sec by using leading 
//spaces to offset the bullet position (*) from the beginning of the line
//horizontal distance travelled by the bullet is given by v * t.
//vertical distance travelled by the bullet is given by 1/2 (g * t^2)
void plot_bullet_positions(int v) { //v for velocity
    const size_t n_positions = 500; //1 position per 0.01 of a sec = 150 positions
    const double g = 9.8; 
    size_t v_distance_already_traveled = 0;
    size_t h_distance_already_traveled = 0;
    cout << '*';
    int vMove;
    int hMove;

    for (size_t t = 0; t < n_positions; t++){ //you've gotta reseach what's the difference between ++i & i++
        double actual_time = t/100.0; //our time is measured in 0.01 of a sec
        size_t h_distance = v * actual_time;
        size_t v_distance = 0.5 * actual_time * actual_time * g;
        size_t v_distance_to_travel = v_distance - v_distance_already_traveled;
        size_t h_distance_to_travel = h_distance - h_distance_already_traveled;
        vMove = 0;
        hMove = 0;

        //skip as many rows as determined by the vertical distance (y)
        //and print a line with the horizontal distance (x) represented by spaces
        //& vertical distance represented by blank lines

        // cout << "t = " << t << ", h_distance = " << h_distance << ", v_distance_to_travel = " << v_distance_to_travel << endl;

        if (v_distance_to_travel == 0) {
        } else {
            for (size_t y=0; y < v_distance_to_travel; y++){
                vMove++;
            }
        }
        if (h_distance == 0){
        } else {
            for (size_t j = 0; j < h_distance; j++) {
                hMove++;
            }
        }
        if (vMove != 0 && hMove != 0) {
            for (size_t i = 0; i < vMove; i++) {
                cout << endl;
            }
            for (size_t k = 0; k < hMove; k++){
                cout << ' ';
            }
            cout << '*';
        }
        v_distance_already_traveled = v_distance;
        // h_distance_already_traveled = h_distance;
    }
}

int main() {
    int speed;

    //print a prompt to ask the user for the inital horizontal speed 
    //& read in the initial speed from the user via cin into speed
    cout << "Please type in the initial horizontal speed: ";
    cin >> speed;
    cout << "\nThe horizontal speed typed: " << speed << endl;

    //call a function and pass it this speed and have it print out the 
    //bullet's trajectory
    plot_bullet_positions(speed);

    return 0;
}