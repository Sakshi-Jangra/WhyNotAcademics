setwd("G:/Sakshi/Cllg Work/3rd year/R")
print(getwd())

grocery_data <-read.csv("grosdatasetweka2.csv")
str(grocery_data)
summary(grocery_data)

head(grocery_data)
colnames <- names(grocery_data)
basket_str <- ""
for ( row in 1:nrow(grocery_data)) {
  if ( row != 1) {
    basket_str <- paste0(basket_str, "\n")
  }
  basket_str <- paste0(basket_str, row,",")
  for (col in 2:length(colnames)) {
    if ( col != 2) {
      basket_str <- paste0(basket_str, ",")
    }
    basket_str <- paste0(basket_str, colnames[col],"=",grocery_data[row,col])
  }
}
write(basket_str,"grocery_data.csv")

library(arules)
newGrocery <- read.transactions("grocery_data.csv",sep=",")
summary(newGrocery)


itemFrequencyPlot(newGrocery,topN=10,type="absolute",col="darkgreen", horiz=TRUE)

rules<-apriori(newGrocery, parameter = list(supp=0.1, conf=0.3))
inspect(rules[1 :50])

itemFrequencyPlot(newGrocery,topN=10,type="absolute",col="darkgreen", horiz=TRUE)
