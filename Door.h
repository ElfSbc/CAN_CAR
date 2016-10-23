// ********************************************************************************
// class Door
// ********************************************************************************
class Door{
	private:
		bool state = false;
	public:
		bool getState();
		void open(){
			state = true;
		};
		void close(){
			state = false;				
		};	
}
