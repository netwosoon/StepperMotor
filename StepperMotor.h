class StepperMotor
{
   	private:
   		int Pin0;
		int Pin1;
		int Pin2;
		int Pin3;
		int _step;
		int max_steps;
		int steps_left;//1 rev
		boolean dir; // gre
		int pos;
	
	public:
		StepperMotor(int p0, int p1, int p2, int p3){
			max_steps = 4096;
			Pin0 = p0;
			Pin1 = p1;
			Pin2 = p2;
			Pin3 = p3;
			_step = 0;
			steps_left = 0;
			dir = false;
			pos = 0;
			setup();
		}

		void setup(){
		    pinMode(Pin0, OUTPUT);
		    pinMode(Pin1, OUTPUT);
		    pinMode(Pin2, OUTPUT);
		    pinMode(Pin3, OUTPUT);
		}

		void step(){
		    switch (_step) {
		    case 0:
		        digitalWrite(Pin0, LOW);
		        digitalWrite(Pin1, LOW);
		        digitalWrite(Pin2, LOW);
		        digitalWrite(Pin3, HIGH);
		        break;
		    case 1:
		        digitalWrite(Pin0, LOW);
		        digitalWrite(Pin1, LOW);
		        digitalWrite(Pin2, HIGH);
		        digitalWrite(Pin3, HIGH);
		        break;
		    case 2:
		        digitalWrite(Pin0, LOW);
		        digitalWrite(Pin1, LOW);
		        digitalWrite(Pin2, HIGH);
		        digitalWrite(Pin3, LOW);
		        break;
		    case 3:
		        digitalWrite(Pin0, LOW);
		        digitalWrite(Pin1, HIGH);
		        digitalWrite(Pin2, HIGH);
		        digitalWrite(Pin3, LOW);
		        break;
		    case 4:
		        digitalWrite(Pin0, LOW);
		        digitalWrite(Pin1, HIGH);
		        digitalWrite(Pin2, LOW);
		        digitalWrite(Pin3, LOW);
		        break;
		    case 5:
		        digitalWrite(Pin0, HIGH);
		        digitalWrite(Pin1, HIGH);
		        digitalWrite(Pin2, LOW);
		        digitalWrite(Pin3, LOW);
		        break;
		    case 6:
		        digitalWrite(Pin0, HIGH);
		        digitalWrite(Pin1, LOW);
		        digitalWrite(Pin2, LOW);
		        digitalWrite(Pin3, LOW);
		        break;
		    case 7:
		        digitalWrite(Pin0, HIGH);
		        digitalWrite(Pin1, LOW);
		        digitalWrite(Pin2, LOW);
		        digitalWrite(Pin3, HIGH);
		        break;
		    default:
		        digitalWrite(Pin0, LOW);
		        digitalWrite(Pin1, LOW);
		        digitalWrite(Pin2, LOW);
		        digitalWrite(Pin3, LOW);
		        break;
		    }
		    if (dir) {
		        _step++;
		    }
		    else {
		        _step--;
		    }
		    if (_step > 7) {
		        _step = 0;
		    }
		    if (_step < 0) {
		        _step = 7;
		    }
		    delay(1);
		}

		boolean run(){
			if(steps_left>0){
		      steps_left--;
		      step();
		      return true;
		    }
		    return false;
		}

		void setDirection(boolean d){
			dir = d;
		}

		void setSteps(int sl){
			steps_left = sl;
		}

		void reverse(){
			dir = !dir;
		}

		void rotate(int deg){
			pos += deg;
			steps_left = map(deg, 0, 360, 0, max_steps);
		}

		void rotateTo(int deg){
			deg = deg - pos;
			rotate(deg);
		}

		void setStepsPerOneRevolution(int spor){
			max_steps = spor;
		}

		void setPosition(int p){
			if(p>360){
				p = 360;
			}
			if(p<0){
				p = 0;
			}
			pos = p;
		}

		int stepsLeft(){
			return steps_left;
		}

		boolean direction(){
			return dir;
		}

		int stepsPerOneRevolution(){
			return max_steps;
		}

		int position(){
			if(steps_left==0){
				return pos;
			}
			else{
				int x = max_steps - steps_left;
				return map(x, 0, max_steps, 0, pos);
			}
		}
};