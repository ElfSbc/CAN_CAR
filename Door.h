// ********************************************************************************
// class Door
// ********************************************************************************
class Door{
	private:
		bool state = false;
	public:
		bool getState(){
			return state;
		};
		void open(){
			state = true;
		};
		void close(){
			state = false;				
		};	
};
