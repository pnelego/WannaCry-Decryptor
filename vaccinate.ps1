#FREE TO USE
#This will disable the SMB1 protocol in windows 10. (note; this protocol isnt used much so its absense 
# is probably called for in most cases).

Set-SmbServerConfiguration -EnableSMB1Protocol $false -Force
sls EnableSMB1Protocol Get-SmbServerConfiguration -ca 