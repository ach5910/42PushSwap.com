from __future__         import unicode_literals
from django.db import models


    
class Executable(models.Model):
    name =  models.CharField(max_length=25)
    t_min_500 = models.IntegerField()
    t_max_500 = models.IntegerField()
    t_avg_500 = models.IntegerField()
    
    def __str__(self):
        return str(self.name)

    def save(self, *args, **kwargs):
    	super(Executable, self).save(*args, **kwargs)