package hogeclass;
use Moose;

has 'moji' => (isa =>'Str', is => 'rw');

package Main;

my $inst = hogeclass->new(moji => 'hogehoge');
print $inst->moji .  "\n";

$inst->moji('fuga');
print $inst->moji . "\n";

