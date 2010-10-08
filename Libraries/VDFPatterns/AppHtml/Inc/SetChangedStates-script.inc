<% if CheckFieldChange<>0 then%>

<script LANGUAGE="JavaScript">
<!--
function SetChangedStates(obj)
{
   var items = obj.length;
   var i, isChanged, pos, itm;
   var str = ":ChangedStates:", s, typ;
   for (i=0; i<items; i++) {
      isChanged=false;
      itm = obj.item(i);
      typ = itm.type;
      s   = itm.name;
      if ( s != "ChangedStates"  &&
          (typ=="text" || typ=="textarea" || typ=="radio" || typ=="hidden" ||
          typ=="checkbox" || typ=="select-one" )) {

          if ( (typ=="text" || typ=="textarea" || typ=="hidden") &&
                itm.defaultValue != itm.value)
                isChanged=true;
          else if (typ=="select-one" ) {
                var opts = itm.length;
                var j;
                for (j=0; j<opts && !isChanged; j++)
                   isChanged=(itm.options(j).defaultSelected != itm.options(j).selected);
          }
          else if ( (typ=="radio" || typ=="checkbox") &&
                itm.defaultChecked != itm.checked)
                isChanged=true;
          pos = str.match(s+":")
          if (!pos)
		       str += (isChanged ? "+" : "-") + s + ":" ;
          else if (isChanged)
              str[pos-1]="+";
      }
   }

   obj.ChangedStates.value = str;

}

// -->
</script>

<% else %>

<script LANGUAGE="JavaScript">
<!--
   function SetChangedStates(obj) {}
// -->
</script>

<% end if %>