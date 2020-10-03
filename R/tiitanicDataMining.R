print(getwd())

setwd("G:/Sakshi/Cllg Work/3rd year/R")
print(getwd())

titanic_data <-read.csv("titanic.csv")
str(titanic_data)

library(arules)
titanic_result <- read.transactions("titanic.csv", sep = ",")
summary(titanic_result)
itemFrequencyPlot(titanic_result,topN=20,type="absolute",
                  col="purple", horiz=TRUE)