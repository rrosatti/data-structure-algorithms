
class Time{
	private:
		int hour;
		int minute;
		int second;
	public: 
		Time(int h = 0, int m = 0, int s = 0);
		int getHour() const;
		void setHour(int h);
		int getMinute() const;
		void setMinute(int m);
		int getSecond() const;
		void setSecond(int s);
		void setTime(int h, int m, int s);
		void nextSecond();
};