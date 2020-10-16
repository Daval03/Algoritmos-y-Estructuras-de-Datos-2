#include "persona.h"
#include "gtest/gtest.h"
namespace{
TEST(persona, getEdad){
    persona aldo(20);
    //EXPECT_EQ("Aldo",aldo.getEdad());
    EXPECT_EQ(20,aldo.getEdad());
}
}
