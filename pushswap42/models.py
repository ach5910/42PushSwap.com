from __future__         import unicode_literals
from django.db import models

from django.db          import models

    
class Executable(models.Model):
    name =  models.CharField(max_length=25)
    s_len = models.IntegerField(default=20)
    s_time = models.FloatField()
    s_moves = models.IntegerField()
    s_pass = models.BooleanField()
    b_len = models.IntegerField(default=1000)
    b_time = models.FloatField()
    b_moves = models.IntegerField()
    b_pass = models.BooleanField()
    
    def __str__(self):
        return str(self.name)