# create a data frame
var1 <- 1:5
var2 <- (5:1)*20
var3 <- c("Sakshi", "Aastha", "Sukriti", "Sanjana", "Souyma")
df1 <- data.frame(var1, var2, var3)
names(df1) <- c("VarInt", "VarReal", "VarChar")
# save to a csv file
write.csv(df1, "./dataforR1.csv", row.names = FALSE)
# read from a csv file
df2 <- read.csv("./dataforR1.csv")
print(df2)