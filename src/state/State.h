#ifndef STATE__
#define STATE__

class State{

    public:
        virtual void onEnter() = 0;
        virtual void handleEvents() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void exit() = 0;
        virtual bool getRestartFlag() = 0;
        virtual bool getIsRunning() = 0;
        virtual ~State() {}
    private:
        bool restartFlag;
        bool isRunning;
};

#endif