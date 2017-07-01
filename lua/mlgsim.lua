doritosCost = 30
doritosCount = 0
doritosPtsTurn = 10
dewPtsTurn = 20
dewCost = 60
dewCount = 0

printf = function(s,...)
           return print(s:format(...))
         end --function declaration of printf
function CalcPtsTurn()
  local dor = doritosCount*doritosPtsTurn
  local dew = dewCount*dewPtsTurn
  return dew+dor
end --CalcPtsTurn function
function main()
  mlgpoints = 100;
  print("\n\t-----MLG Simulator by Alex Pawelko-----")
  for i=1,15,1
  do
    printf("\n\tYou are on turn %i.",i)
    if(i > 1) then
      printf("\n\tYou earned %i MLG Points this turn!",CalcPtsTurn())
    end
    mlgpoints = mlgpoints + CalcPtsTurn()
    printf("\n\tYou have %i MLG Points.",mlgpoints)
    printf("\n\tCurrently you have %i Doritos and %d litre(s) of Mountain Dew.",doritosCount,dewCount)
    
    printf("\n\tDo you want to buy any Doritos? Doritos cost %i and earn %d MLG Points per turn. If you do not want to buy any type 0.",doritosCost,doritosPtsTurn)
    amount = io.read("*number")
    if(amount == nil) then
      print("You fail, that's not an integer!")
      return nil;
    elseif amount % 1 ~= 0 then
      print("You fail, that's not an integer!")
      return nil;
    end --if statement
    if amount > 0 then
      for attempt = 0,amount-1,1 do
        if ((mlgpoints - doritosCost) >= 0) then
          doritosCount = doritosCount + 1
          mlgpoints = mlgpoints - doritosCost
        else 
          print("You didn't have enough MLG Points to buy all those Doritos!")
          break
        end --if statement  
      end --for loop
      printf("\n\tYou now have %i Dorito(s)!",doritosCount)
    elseif amount < 0 then
      print("\n\tMATH DOESN'T WORK THAT WAY!")
    end --if statement
    
    
    printf("\n\tDo you want to buy Mountain Dew? Mountain Dew costs %i per litre and earns %d MLG Points per turn. If you do not want to buy any type 0.",dewCost,dewPtsTurn)
    amount = io.read("*number")
    if(amount == nil) then
      print("You fail, that's not an integer!")
      return nil;
    elseif amount % 1 ~= 0 then
      print("You fail, that's not an integer!")
      return nil;
    end --if statement
    if amount > 0 then
      for attempt = 0,amount-1,1 do
        if mlgpoints - dewCost >= 0 then
          dewCount = dewCount + 1
          mlgpoints = mlgpoints - dewCost
        else 
          print("You didn't have enough MLG Points to buy all that Mountain Dew!")
          break
        end --if statement  
      end --for loop
      printf("\n\tYou now have %i litre(s) of Mountain Dew!",dewCount)
    elseif amount < 0 then
      print("\n\tMATH DOESN'T WORK THAT WAY!")
    end --if statement
    printf("\n\tTurn %i has ended.",i)
    print("\n\t------------------------------------------------");
  end --for loop
end --main function
main();
