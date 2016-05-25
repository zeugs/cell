#pragma once

#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

class Automaton {
private:
    virtual bool shouldLive(int posX, int posY) = 0;
public:
    long runCount;
    virtual void initialize(int initMethod) = 0;
    virtual void evaluate() = 0;
    virtual void render() = 0;
};

#endif // AUTOMATON_HPP
