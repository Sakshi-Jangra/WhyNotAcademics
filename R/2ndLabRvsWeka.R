print(getwd())

data <- read.csv("tit.csv")
print(data)

library(arules)
rules <- apriori(tit.csv)
inspect(rules)

str(titanic.raw)
print(str)
library(arules)
rules <- apriori(titanic.raw)
inspect(rules)

data <- read.csv("tit.csv")
print(data)
library(arules)
rules <- apriori(tit.csv)

library(arulesViz)
plot(rules)

library(arulesViz)
plot(rules, method="paracoord", control=list(reorder=TRUE))