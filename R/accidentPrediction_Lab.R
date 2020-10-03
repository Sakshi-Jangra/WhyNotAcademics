print(getwd())

setwd("G:/Sakshi/Cllg Work/3rd year/R")
print(getwd())

titanic_data <-read.csv("titanic.csv")
str(titanic_data)

library(arules)
titanic_result <- read.transactions("titanic.csv", sep = ",")
summary(titanic_result)


itemFrequencyPlot(titanic_result,topN=10,type="absolute",
                  col="orange", horiz=TRUE)




























print(getwd())

setwd("G:/Sakshi/Cllg Work/3rd year/R")
print(getwd())

accident_data <-read.csv("accidents.csv")
str(accident_data)

library(arules)
accident_result <- read.transactions("accidents.csv", sep = ",")
summary(accident_result)

itemFrequencyPlot(accident_result,topN=20,type="absolute",col="pink", horiz=FALSE)













print(getwd())

setwd("G:/Sakshi/Cllg Work/3rd year/R")
print(getwd())

accident_data <-read.csv("accidents.csv")
str(accident_data)
summary(accidents)

head(accident_data)

colnames <- names(accident_data)
basket_str <- ""
for ( row in 1:nrow(accident_data)) {
  if ( row != 1) {
    basket_str <- paste0(basket_str, "\n")
  }
  basket_str <- paste0(basket_str, row,",")
  for (col in 2:length(colnames)) {
    if ( col != 2) {
      basket_str <- paste0(basket_str, ",")
    }
    basket_str <- paste0(basket_str, colnames[col],"=",accident_data[row,col])
  }
}
write(basket_str,"accidents_basket.csv")


library(arules)
accidents <- read.transactions("accidents_basket.csv",sep=",")

summary(accidents)


itemFrequencyPlot(accidents,topN=10,type="absolute",col="darkgreen", horiz=TRUE)

rules<-apriori(accidents, parameter = list(supp=0.1, conf=0.3))
inspect(rules[1 :50])



# library(gglpot2)
# ggplot2(accident_result, aes(displ, hwy, colour = class)) + geom_point()


# library(ggplot2)
