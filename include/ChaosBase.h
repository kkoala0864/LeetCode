class ChaosBase {
	public :
		ChaosBase() {}
		virtual void DebugPrint() {}
		virtual ~ChaosBase() {}
	private :
		ChaosBase(const ChaosBase&);
		ChaosBase& operator=(const ChaosBase& source);
};
